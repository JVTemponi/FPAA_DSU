#ifndef DSU_INGENUA_HPP
#define DSU_INGENUA_HPP

#include "ConjuntosDisjuntosBase.hpp"
//
//1. Naive (Ingênua): Implementação básica sem heurı́sticas de balanceamento ou compressão.
//
class DSUIngenua : public ConjuntosDisjuntosBase {
public:
    DSUIngenua(int n);
    int buscar(int vertice) override;
    bool unir(int vertice1, int vertice2) override;
};

#endif