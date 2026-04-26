#ifndef ARESTA_HPP
#define ARESTA_HPP

struct Aresta {
    int origem;
    int destino;
    int peso;
};

/// @brief Comparar duas arestas pelo peso. 
/// @param a Aresta 1
/// @param b Aresta 2
/// @return true se a.peso < b.peso, false caso contrário
inline bool compararArestasPorPeso(const Aresta &a, const Aresta &b) {
    return a.peso < b.peso;
}

#endif