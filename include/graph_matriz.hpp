#ifndef GRAPH_HPP
#define GRAPH_HPP

class Graph {
public:
  Graph(int vertices);
  ~Graph();

  void addEdge(int u, int v, int weight);
  void removeEdge(int u, int v);
  int getWeight(int u, int v) const;
  void print() const;

private:
  int** adjMatrix;
  int numVertices;
};

#endif // GRAPH_HPP
