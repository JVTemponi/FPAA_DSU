# Análise Comparativa de Eficiência: Disjoint Set Union (DSU)

Este projeto realiza uma análise experimental de performance e eficiência de memória entre diferentes variantes da estrutura de dados **Disjoint Set Union (DSU)**, integradas ao algoritmo de Kruskal para identificação de Árvores Geradoras Mínimas (MST).

## Como Executar

O fluxo de trabalho consiste na geração de instâncias de grafos via script python e na execução dos testes de performance em C++.

### 1. Geração do Grafo de Entrada
O script Python gera grafos conexos parametrizados e os exporta para um formato estruturado.

```bash
# Navegue até o diretório do script
cd FPAA_DSU/impl_py/

# Execute informando a quantidade de vértices e arestas diretamente nas variáveis VERTICES e ARESTAS
python3 script_gerador_grafo.py
```
### 2. Compilação e Execução (C++)
A implementação principal foi desenvolvida em C++. Para executar:
```bash

# Navegue até o diretório da implementação C++
cd FPAA_DSU/impl_cpp/

# Compile o código fonte
g++ src/*.cpp -I include -o build/dsu_exec

# Execute os testes
./build/dsu_exec
```

