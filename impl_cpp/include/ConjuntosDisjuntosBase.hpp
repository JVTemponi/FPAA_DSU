#ifndef CONJUNTOS_DISJUNTOS_BASE_HPP
#define CONJUNTOS_DISJUNTOS_BASE_HPP

#include <vector>

class ConjuntosDisjuntosBase {
    protected:
        std::vector<int> pai;
        std::vector<int> altura;
        long acessos_memoria;

    public:
        ConjuntosDisjuntosBase(int quantidade_vertices);
        virtual ~ConjuntosDisjuntosBase() = default;

        /// @brief Buscar a raiz do conjunto que o vertice pertence
        /// @param vertice Vertice a ser buscado
        /// @return Raiz do conjunto que o vertice pertence
        virtual int buscar(int vertice) = 0;
        
        /// @brief Unir o vertice1 e vertice2 no mesmo conjunto.
        /// @param vertice1 Vertice 1 a ser unido
        /// @param vertice2 Vertice 2 a ser unido
        /// @return true se a união foi realizada, false se já pertenciam ao mesmo conjunto
        virtual bool unir(int vertice1, int vertice2) = 0;

        /// @brief Ler o pai de um vertice
        /// @param vertice Vertice a ser lido
        /// @return Pai do vertice
        int ler_pai(int vertice);

        /// @brief Escrever o pai de um vertice
        /// @param vertice Vertice a ser modificado
        /// @param novoPai Novo pai do vertice
        void escrever_pai(int vertice, int novo_pai);

        /// @brief Ler a altura de um vertice
        /// @param vertice Vertice a ser lido
        /// @return Altura do vertice
        int ler_altura(int vertice);

        /// @brief Incrementar a altura de um vertice
        /// @param vertice Vertice a ser modificado
        void incrementar_altura(int vertice);

        /// @brief Obter o número de acessos a memória
        /// @return Número de acessos a memória
        long long obter_acessos_memoria() const;
};

#endif