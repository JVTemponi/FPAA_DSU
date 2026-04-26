#include "DSUTarjanOtm.hpp"

DSUTarjanOtm::DSUTarjanOtm(int n) : ConjuntosDisjuntosBase(n) {}

//Implementação anterior
// int DSUTarjanOtm::buscar(int vertice) {
//     int pai_atual = ler_pai(vertice);
//     if (pai_atual != vertice) {
//         int novo_pai = buscar(pai_atual);
//         escrever_pai(vertice, novo_pai);
//     }
//     return ler_pai(vertice);
// }


//Implementação otimizada para reduzir os acessos à memória
int DSUTarjanOtm::buscar(int vertice) {
    int pai_atual = ler_pai(vertice);
    if (pai_atual == vertice) {
        return vertice;
    }
    int novo_pai = buscar(pai_atual);
    escrever_pai(vertice, novo_pai);
    return novo_pai;
}

bool DSUTarjanOtm::unir(int vertice1, int vertice2) {
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