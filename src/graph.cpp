#include "../include/graph.hpp"
// construtor
Graph::Graph(){
  vertexCount = 0;
  edgeCount = 0;
  vertices = new Vertex[100];
  edges = new Edge[100];
}
// destrutor
Graph::~Graph() {
  delete[] vertices;
  delete[] edges;
}

float Graph::distance(Vertex v1, Vertex v2){
  return sqrt(pow(v1.x - v2.x, 2) + pow(v1.y - v2.y, 2));
}
void Graph::addVertex(float x, float y){
  Vertex v;
  v.x = x;
  v.y = y;
  vertices[vertexCount] = v;
  vertexCount++;
}
