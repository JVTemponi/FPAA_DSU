#include "DSUIngenua.hpp"

DSUIngenua::DSUIngenua(int n) : ConjuntosDisjuntosBase(n) {}

int DSUIngenua::buscar(int vertice) {
    int atual = vertice;
    while (ler_pai(atual) != atual) {
        atual = ler_pai(atual);
    }
    return atual;
}

bool DSUIngenua::unir(int vertice1, int vertice2) {
    int raiz1 = buscar(vertice1);
    int raiz2 = buscar(vertice2);
    if (raiz1 != raiz2) {
        escrever_pai(raiz2, raiz1);
        return true;
    }
    return false;
}