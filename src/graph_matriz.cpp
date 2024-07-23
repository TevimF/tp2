#include "../include/graph_matriz.hpp"
#include <iostream>

// biblioteca para formatar a saída
#include <iomanip>

Graph::Graph(int vertices) : numVertices(vertices) {
  //inicializa a matriz de adjacência
  adjMatrix = new int*[numVertices];
  for (int i = 0; i < numVertices; ++i) {
    adjMatrix[i] = new int[numVertices];
    for (int j = 0; j < numVertices; ++j) {
        adjMatrix[i][j] = 0; // Inicializa com 0 (sem arestas)
    }
  }
}

Graph::~Graph() {
  for (int i = 0; i < numVertices; ++i) {
    delete[] adjMatrix[i];
  }
  delete[] adjMatrix;
}

void Graph::addEdge(int u, int v, int weight) {
  if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
    adjMatrix[u][v] = weight;
    adjMatrix[v][u] = weight; // Para grafos não direcionados
  }
}

void Graph::removeEdge(int u, int v) {
  if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
    adjMatrix[u][v] = 0;
    adjMatrix[v][u] = 0; // Para grafos não direcionados
  }
}

int Graph::getWeight(int u, int v) const {
  if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
    return adjMatrix[u][v];
  }
  return -1; // Indica que a aresta não existe ou índices inválidos
}

void Graph::print() const {
  for (int i = 0; i < numVertices; ++i) {
    for (int j = 0; j < numVertices; ++j) {
      std::cout << std::setw(4) << adjMatrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}
