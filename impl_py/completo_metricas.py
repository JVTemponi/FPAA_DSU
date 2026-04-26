import time

class DSUBase:
    def __init__(self, quantidade_vertices):
        self.pai = list(range(quantidade_vertices))
        self.altura = [0] * quantidade_vertices
        self.acessos_memoria = 0

    def ler_pai(self, vertice):
        self.acessos_memoria += 1
        return self.pai[vertice]

    def escrever_pai(self, vertice, novo_pai):
        self.acessos_memoria += 1
        self.pai[vertice] = novo_pai

    def ler_altura(self, vertice):
        self.acessos_memoria += 1
        return self.altura[vertice]

    def incrementar_altura(self, vertice):
        self.acessos_memoria += 1
        self.altura[vertice] += 1

    def buscar(self, vertice): pass
    def unir(self, vertice1, vertice2): pass


class DSUIngenua(DSUBase):
    def buscar(self, vertice):
        atual = vertice
        while self.ler_pai(atual) != atual:
            atual = self.ler_pai(atual)
        return atual

    def unir(self, vertice1, vertice2):
        raiz1 = self.buscar(vertice1)
        raiz2 = self.buscar(vertice2)
        if raiz1 != raiz2:
            self.escrever_pai(raiz2, raiz1)
            return True
        return False


class DSURank(DSUBase):
    def buscar(self, vertice):
        atual = vertice
        while self.ler_pai(atual) != atual:
            atual = self.ler_pai(atual)
        return atual

    def unir(self, vertice1, vertice2):
        raiz1 = self.buscar(vertice1)
        raiz2 = self.buscar(vertice2)
        if raiz1 == raiz2: return False

        altura1 = self.ler_altura(raiz1)
        altura2 = self.ler_altura(raiz2)

        if altura1 < altura2:
            self.escrever_pai(raiz1, raiz2)
        elif altura1 > altura2:
            self.escrever_pai(raiz2, raiz1)
        else:
            self.escrever_pai(raiz2, raiz1)
            self.incrementar_altura(raiz1)
        return True


class DSUTarjan(DSUBase):
    def buscar(self, vertice):
        pai_atual = self.ler_pai(vertice)
        if pai_atual != vertice:
            novo_pai = self.buscar(pai_atual)
            self.escrever_pai(vertice, novo_pai)
        return self.ler_pai(vertice)

    def unir(self, vertice1, vertice2):
        raiz1 = self.buscar(vertice1)
        raiz2 = self.buscar(vertice2)
        if raiz1 == raiz2: return False

        altura1 = self.ler_altura(raiz1)
        altura2 = self.ler_altura(raiz2)

        if altura1 < altura2:
            self.escrever_pai(raiz1, raiz2)
        elif altura1 > altura2:
            self.escrever_pai(raiz2, raiz1)
        else:
            self.escrever_pai(raiz2, raiz1)
            self.incrementar_altura(raiz1)
        return True


def processar_arquivo(nome_arquivo):
    arestas = []
    maior_vertice_encontrado = -1

    with open(nome_arquivo, 'r') as arquivo:
        for linha in arquivo:
            linha = linha.strip()
            if not linha: continue
            
            colunas = linha.split(';')
            origem, destino, peso = int(colunas[0]), int(colunas[1]), int(colunas[2])
            arestas.append((peso, origem, destino))
            maior_vertice_encontrado = max(maior_vertice_encontrado, origem, destino)

    quantidade_vertices = maior_vertice_encontrado + 1
    return quantidade_vertices, arestas


def executar_experimento(nome_variante, dsu, quantidade_vertices, arestas):
    peso_total_mst = 0
    arestas_selecionadas = 0

    inicio_tempo = time.perf_counter_ns()

    for peso, origem, destino in arestas:
        if dsu.unir(origem, destino):
            peso_total_mst += peso
            arestas_selecionadas += 1
            if arestas_selecionadas == quantidade_vertices - 1:
                break

    fim_tempo = time.perf_counter_ns()
    
    duracao_microsegundos = (fim_tempo - inicio_tempo) / 1000.0

    print(f"--- {nome_variante} ---")
    print(f"Tempo de Execucao : {duracao_microsegundos:.2f} microssegundos")
    print(f"Acessos a Memoria : {dsu.acessos_memoria} acessos")
    print(f"Peso da MST       : {peso_total_mst}\n")


if __name__ == "__main__":
    nome_do_arquivo = '../grafos/grafo.txt'
    
    try:
        qtd_vertices, lista_arestas = processar_arquivo(nome_do_arquivo)
        print(f"Grafo carregado! Vertices: {qtd_vertices}, Arestas: {len(lista_arestas)}\n")

        lista_arestas.sort()
        dsu_ingenua = DSUIngenua(qtd_vertices)
        dsu_rank = DSURank(qtd_vertices)
        dsu_tarjan = DSUTarjan(qtd_vertices)

        print("RESULTADOS DO EXPERIMENTO:\n")
        executar_experimento("1. Variante Ingenua", dsu_ingenua, qtd_vertices, lista_arestas)
        executar_experimento("2. Variante Union by Rank", dsu_rank, qtd_vertices, lista_arestas)
        executar_experimento("3. Variante Full Tarjan", dsu_tarjan, qtd_vertices, lista_arestas)

    except FileNotFoundError:
        print(f"Erro: O arquivo '{nome_do_arquivo}' não foi encontrado.")