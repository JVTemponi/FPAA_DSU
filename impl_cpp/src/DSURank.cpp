#include "DSURank.hpp"

DSURank::DSURank(int n) : ConjuntosDisjuntosBase(n) {}

int DSURank::buscar(int vertice) {
    int atual = vertice;
    while (ler_pai(atual) != atual) {
        atual = ler_pai(atual);
    }
    return atual;
}

bool DSURank::unir(int vertice1, int vertice2) {
    int raiz1 = buscar(vertice1);
    int raiz2 = buscar(vertice2);
    if (raiz1 == raiz2)
        return false;

    int altura1 = ler_altura(raiz1);
    int altura2 = ler_altura(raiz2);

    if (altura1 < altura2) {
        escrever_pai(raiz1, raiz2);
    } else if (altura1 > altura2) {
        escrever_pai(raiz2, raiz1);
    } else {
        escrever_pai(raiz2, raiz1);
        incrementar_altura(raiz1);
    }
    return true;
}