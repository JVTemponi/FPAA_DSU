#ifndef GRAFO_UTILS_HPP
#define GRAFO_UTILS_HPP

#include <string>
#include <vector>
#include "Aresta.hpp"
#include "ConjuntosDisjuntosBase.hpp"

/// @brief Formata o tempo em um string legível.
/// @param segundos Tempo em segundos
/// @return String formatada representando o tempo em microssegundos, milissegundos, segundos ou minutos e segundos, dependendo do valor de entrada
std::string formatar_tempo(double segundos);

/// @brief Processa um arquivo texto contendo os dados do grafo (origem;destino;peso).  
/// @param arquivo_grafo Caminho completo para o arquivo
/// @param quantidade_vertices Variável para armazenar a quantidade de vértices encontrados
/// @param arestas Variável para armazenar as arestas do grafo
/// @return Valor booleano indicando sucesso ou falha na leitura do arquivo
bool processar_grafo(const std::string &arquivo_grafo, int &quantidade_vertices, std::vector<Aresta> &arestas);

/// @brief Executa a implementação do DSU de acordo com a variante especificada, medindo o tempo de execução, acessos a memória e peso total da MST.
/// @param nome_implementacao Referência para o nome da implementação a ser exibida nos resultados
/// @param dsu Referência para a instância DSU implementada
/// @param quantidade_vertices Quantidade de vértices do grafo
/// @param arestas Referência para o vetor de arestas do grafo, ordenado por peso
void executar_implementacao_dsu(const std::string &nome_implementacao, ConjuntosDisjuntosBase &dsu, int quantidade_vertices, const std::vector<Aresta> &arestas);

#endif