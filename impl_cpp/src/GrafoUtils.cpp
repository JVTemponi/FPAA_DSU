#include "GrafoUtils.hpp"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <algorithm>

std::string formatar_tempo(double segundos) {
    std::stringstream formato;
    
    if (segundos < 0.001) {
        formato << (segundos * 1000000.0) << " microssegundos";
    } else if (segundos < 1.0) {
        formato << std::fixed << std::setprecision(2) << (segundos * 1000.0) << " milissegundos";
    } else if (segundos < 60.0) {
        formato << std::fixed << std::setprecision(4) << segundos << " segundos";
    } else {
        int minutos = static_cast<int>(segundos) / 60;
        double segundos_restantes = segundos - (minutos * 60);
        formato << minutos << " minutos e " 
                << std::fixed << std::setprecision(2) << segundos_restantes << " segundos";
    }
    
    return formato.str();
}

bool processar_grafo(const std::string &arquivo_grafo, int &quantidade_vertices, std::vector<Aresta> &arestas) {
    std::ifstream arquivo(arquivo_grafo);
    
    if (!arquivo.is_open()) {
        return false;
    }

    std::string linha;
    int maior_id_vertice = -1;

    while (std::getline(arquivo, linha)) {
        if (linha.empty()) {
            continue;
        }
        
        std::stringstream texto_linha(linha);
        std::string texto_coluna;
        int origem, destino, peso;

        if (std::getline(texto_linha, texto_coluna, ';')) {
            origem = std::stoi(texto_coluna);
        }
        if (std::getline(texto_linha, texto_coluna, ';')) {
            destino = std::stoi(texto_coluna);
        }
        if (std::getline(texto_linha, texto_coluna, ';')) {
            peso = std::stoi(texto_coluna);
        }

        arestas.push_back({origem, destino, peso});
        maior_id_vertice = std::max({maior_id_vertice, origem, destino});
    }

    arquivo.close();
    
    quantidade_vertices = maior_id_vertice + 1;
    return true;
}

void executar_implementacao_dsu(const std::string &nome_implementacao, ConjuntosDisjuntosBase &dsu, int quantidade_vertices, const std::vector<Aresta> &arestas) {
    long peso_total_mst = 0;
    int arestas_selecionadas = 0;

    auto inicio_exec = std::chrono::high_resolution_clock::now();

    for (const Aresta &aresta : arestas) {
        if (dsu.unir(aresta.origem, aresta.destino)) {
            peso_total_mst += aresta.peso;
            arestas_selecionadas++;
            if (arestas_selecionadas == quantidade_vertices - 1)
                break;
        }
    }

    auto fim_exec = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracao_segundos = fim_exec - inicio_exec;

    std::cout << "--- " << nome_implementacao << " ---\n";
    std::cout << "Tempo de Execucao : " << formatar_tempo(duracao_segundos.count()) << "\n";
    std::cout << "Acessos a Memoria : " << dsu.obter_acessos_memoria() << " acessos\n";
    std::cout << "Peso da MST       : " << peso_total_mst << "\n\n";
}