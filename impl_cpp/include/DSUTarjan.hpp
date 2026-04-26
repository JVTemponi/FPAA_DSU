#ifndef DSU_TARJAN_HPP
#define DSU_TARJAN_HPP

#include "ConjuntosDisjuntosBase.hpp"

//
//3. Full Tarjan: Implementação utilizando Union by Rank em conjunto com Path Compression, atingindo a complexidade amortizada de O(α(n)), onde α é a inversa da função de Ackermann.
//
class DSUTarjan : public ConjuntosDisjuntosBase {
public:
    DSUTarjan(int n);
    int buscar(int vertice) override;
    bool unir(int vertice1, int vertice2) override;
};

#endif