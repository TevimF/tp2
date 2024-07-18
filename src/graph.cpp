#include "../include/graph.hpp"

Graph::Graph(){
  vertexCount = 0;
  edgeCount = 0;
  vertices = new Vertex[VECTOR_SIZE];
  edges = new Edge[VECTOR_SIZE];
}

Graph::~Graph(){
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

void Graph::addEdge(Vertex v1, Vertex v2){
  Edge e;
  e.v1 = v1;
  e.v2 = v2;
  e.size = distance(v1, v2);
  edges[edgeCount] = e;
  edgeCount++;
}


