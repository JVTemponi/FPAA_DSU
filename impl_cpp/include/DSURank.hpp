#ifndef DSU_RANK_HPP
#define DSU_RANK_HPP

#include "ConjuntosDisjuntosBase.hpp"

//
//2. Union by Rank: Implementação utilizando a heurı́stica de união pela altura (ou tamanho) da árvore, garantindo complexidade O(log n).
//
class DSURank : public ConjuntosDisjuntosBase {
public:
    DSURank(int n);
    int buscar(int vertice) override;
    bool unir(int vertice1, int vertice2) override;
};

#endif