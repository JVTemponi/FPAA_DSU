import numpy as np
VERTICES = 10
ARESTAS = 100
CAMINHO = "../grafos/"
LOTE = 10000000

def gerar_grafo(qtd_vertices, qtd_arestas, nome_arquivo="grafo.txt"):
    if qtd_arestas < qtd_vertices - 1:
        print("Erro: O grafo precisa de V-1 arestas.")
        return

    rng = np.random.default_rng()
    
    with open(f"{CAMINHO}{nome_arquivo}", 'w') as f:
        origens = np.arange(1, qtd_vertices, dtype=np.int32)
        destinos = (rng.random(qtd_vertices - 1) * origens).astype(np.int32)
        pesos = rng.integers(1, 101, size=qtd_vertices - 1, dtype=np.int8)
        
        u = np.minimum(origens, destinos)
        v = np.maximum(origens, destinos)
        
        arvore = np.column_stack((u, v, pesos))
        np.savetxt(f, arvore, fmt='%d;%d;%d')
        
        del origens, destinos, u, v, arvore 
        
        arestas_restantes = qtd_arestas - (qtd_vertices - 1)
        geradas = 0
        
        while geradas < arestas_restantes:
            lote_atual = min(LOTE, arestas_restantes - geradas)
            
            orig = rng.integers(0, qtd_vertices, size=lote_atual, dtype=np.int32)
            dest = rng.integers(0, qtd_vertices, size=lote_atual, dtype=np.int32)
            
            validas = orig != dest
            orig = orig[validas]
            dest = dest[validas]
            
            if len(orig) == 0:
                continue
                
            pesos = rng.integers(1, 101, size=len(orig), dtype=np.int8)
            
            u = np.minimum(orig, dest)
            v = np.maximum(orig, dest)
            
            chunk = np.column_stack((u, v, pesos))
            np.savetxt(f, chunk, fmt='%d;%d;%d')
            
            geradas += len(orig)

    print(f"{nome_arquivo} com {qtd_vertices} vértices e {qtd_arestas} arestas.")

gerar_grafo(VERTICES, ARESTAS, "grafo.txt")