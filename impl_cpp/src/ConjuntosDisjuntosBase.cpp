#include "ConjuntosDisjuntosBase.hpp"

ConjuntosDisjuntosBase::ConjuntosDisjuntosBase(int quantidade_vertices) {
    pai.resize(quantidade_vertices);
    altura.assign(quantidade_vertices, 0);
    acessos_memoria = 0;
    for (int i = 0; i < quantidade_vertices; i++)
        pai[i] = i;
}

int ConjuntosDisjuntosBase::ler_pai(int vertice) {
    acessos_memoria++;
    return pai[vertice];
}

void ConjuntosDisjuntosBase::escrever_pai(int vertice, int novo_pai) {
    acessos_memoria++;
    pai[vertice] = novo_pai;
}

int ConjuntosDisjuntosBase::ler_altura(int vertice) {
    acessos_memoria++;
    return altura[vertice];
}

void ConjuntosDisjuntosBase::incrementar_altura(int vertice) {
    acessos_memoria++;
    altura[vertice]++;
}

long long ConjuntosDisjuntosBase::obter_acessos_memoria() const { 
    return acessos_memoria; 
}