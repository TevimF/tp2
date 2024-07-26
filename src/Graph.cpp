#include "../include/Graph.hpp"

GraphMatrix::GraphMatrix(int vertices) : vertices(vertices) {
    matrix = new int*[vertices];
    for (int i = 0; i < vertices; i++) {
        matrix[i] = new int[vertices];
        for (int j = 0; j < vertices; j++) {
            matrix[i][j] = 0;
        }
    }
}
// Destructor
    GraphMatrix::~GraphMatrix() {
    for (int i = 0; i < vertices; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}
// Add Edge
void GraphMatrix::addEdge(int source, int destination, int weight) {
    matrix[source][destination] = weight;
}
// Print Graph
void GraphMatrix::printGraph() {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}



// Constructor
GraphList::GraphList(int vertices) : vertices(vertices) {
    list = new Node*[vertices];
    for (int i = 0; i < vertices; i++) {
        list[i] = nullptr;
    }
}
// Destructor
GraphList::~GraphList() {
    for (int i = 0; i < vertices; i++) {
        Node* current = list[i];
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
    delete[] list;
}

// Add Edge
void GraphList::addEdge(int source, int destination, float weight) {
    Node* newNode = new Node;
    newNode->data = destination;
    newNode->weight = weight;
    newNode->next = list[source];
    list[source] = newNode;
}
// Print Graph
void GraphList::printGraph() {
    for (int i = 0; i < vertices; i++) {
        Node* current = list[i];
        while (current != nullptr) {
            cout << "Vértice " << i << " conectado a: ";
            cout << current->data << " tamanho: " << current->weight << " " << endl;
            current = current->next;
        }
    }
}
