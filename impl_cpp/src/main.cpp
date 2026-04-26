#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Aresta.hpp"
#include "DSUIngenua.hpp"
#include "DSURank.hpp"
#include "DSUTarjan.hpp"
#include "DSUTarjanOtm.hpp"
#include "GrafoUtils.hpp"

int main() {
    std::string arquivo_grafo = "../../grafos/grafo.txt";    
    std::vector<Aresta> arestas;
    int quantidade_vertices = 0;
    
    if (!processar_grafo(arquivo_grafo, quantidade_vertices, arestas)) {
        std::cerr << "Erro: Nao foi possivel abrir o arquivo '" << arquivo_grafo << "'.\n";
        return 1;
    }
    std::cout << "Grafo carregado! Vertices: " << quantidade_vertices << ", Arestas: " << arestas.size() << "\n\n";

    // Ordenar as arestas por peso
    std::sort(arestas.begin(), arestas.end(), compararArestasPorPeso);
    
    DSUIngenua dsuIngenua(quantidade_vertices);
    DSURank dsuRank(quantidade_vertices);
    DSUTarjan dsuTarjan(quantidade_vertices);
    DSUTarjanOtm dsuTarjanOtm(quantidade_vertices);

    std::cout << "RESULTADOS DO EXPERIMENTO:\n\n";
    executar_implementacao_dsu("1. Variante Ingenua", dsuIngenua, quantidade_vertices, arestas);
    executar_implementacao_dsu("2. Variante Union by Rank", dsuRank, quantidade_vertices, arestas);
    executar_implementacao_dsu("3. Variante Full Tarjan", dsuTarjan, quantidade_vertices, arestas);
    executar_implementacao_dsu("4. Variante Full Tarjan Otimizada", dsuTarjanOtm, quantidade_vertices, arestas);

    return 0;
}