#ifndef GRAPH_HPP
#define GRAPH_HPP
#include "PriorityQueue.hpp"
#include "MinHeap.hpp"
#include <iostream>
#include <cmath>

using namespace std;

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
    Node** list;
    int vertices;
public:
    // Constructor
    GraphList(int vertices);
    // Destructor
    ~GraphList();
    // Calculate distance
    float distance(int x1, int y1, int x2, int y2);
    // Add Edge
    void addEdge(int source, int destination, float weight);
    // Print Graph
    void printGraph();
    // Dijkstra
    void dijkstra(int source, int destination);
};

#endif // GRAPH_HPP