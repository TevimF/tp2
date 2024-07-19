#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <cmath>

const int VECTOR_SIZE = 100;

// ponto
struct Vertex{
  float x;
  float y;
};
// aresta
struct Edge{
  Vertex v1;
  Vertex v2;
  float size;
};
// grafo
class Graph{
  public:
    Graph();
    ~Graph();
    // distancia entre dois pontos ( tamanho da aresta )
    float distance(Vertex v1, Vertex v2);

    void addVertex(float x, float y);
    void addEdge(Vertex v1, Vertex v2);

  private:
    Vertex* vertices;
    Edge* edges;
    int vertexCount;
    int edgeCount;
};

#endif // GRAPH_HPP