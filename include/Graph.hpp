#ifndef GRAPH_HPP
#define GRAPH_HPP
#include "PriorityQueue.hpp"
#include "MinHeap.hpp"
#include <iostream>
#include <cmath>

using namespace std;

struct coord {
    int x, y;
};
float distance(int x1, int y1, int x2, int y2);

class GraphMatrix {
    int** matrix;
    int vertices;
public:
    // Constructor
    GraphMatrix(int vertices);
    // Destructor
    ~GraphMatrix();
    // Add Edge
    void addEdge(int source, int destination, int weight);
    // Print Graph
    void printGraph();
};

class GraphList {
    struct Node {
        int data;
        float weight;
        Node* next;
    };
    // armazena a lista de adjacência
    Node** list;
    // quantidade de vértices
    int vertices;
    int portais;
    int passes;
public:
    // Constructor
    GraphList(int vertices);
    // Destructor
    ~GraphList();
    // Add Edge
    void addEdge(int source, int destination, float weight);
    // Print Graph
    void printGraph();
    // Dijkstra Algorithm
    float dijkstra_list(int source, int destination);
    // A* Algorithm
    float a_star(int source, int destination, coord* clareiras);
    // Heuristic Function
    float heuristic(int x1, int y1, int x2, int y2);
    // Add passes
    void setPasses(int passes);
};

#endif // GRAPH_HPP;