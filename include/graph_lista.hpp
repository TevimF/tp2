#ifndef GRAFO_LISTA_HPP
#define GRAFO_LISTA_HPP

typedef struct adjacencia_lista_adjacencia  {
    int vertice; // Vértice de destino
    float peso; // Peso associado à aresta
    struct adjacencia *prox; // Próximo elemento da lista de adjacências
} ADJACENCIA;

typedef struct vertice_lista_adjacencia {
    ADJACENCIA *lista; // Cabeça da lista de adjacências
} VERTICE;

typedef struct grafo_lista_adjacencia { 
    int qtd_vertices; // Quantidade total de vértices
    int qtd_arestas;  // Quantidade total de arestas
    VERTICE *adj;     // Array de vértices
} GRAFO;

#endif // GRAFO_LISTA_HPP
