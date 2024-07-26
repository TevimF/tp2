#include "../include/Graph.hpp"

float distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
};
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
    portais = 0;
    passes = 0;
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
    if (weight == 0) {
        portais++;
    }
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
// Dijkstra
float GraphList::dijkstra_list(int source, int destination) {
    MinHeap heap(vertices);
    // array de distâncias
    float* distancias = new float[vertices];
    for (int i = 0; i < vertices; i++) {
        distancias[i] = INFINITY;
    }
    distancias[source] = 0;
    heap.insert(source);
    while (heap.getSize() > 0) {
        int u = heap.extractMin();
        // pega a lista de adjacência do vértice u
        auto current = list[u];
        while (current != nullptr) { 
            if (list[u] != list[source] && current->weight == 0) {
                // obs, a raiz também tem peso 0
                // se é um portal, precisa de um passe
                if (passes <= 0) {
                    // se não tem mais passes, não pode passar
                    // para o próximo vértice
                    break;
                }else {
                    passes--;
                }
            }
            if (distancias[current->data] > distancias[u] + current->weight) {
                distancias[current->data] = distancias[u] + current->weight;
                heap.insert(current->data);
            }
            current = current->next;
        }
    }
    // imprime a menor distancia do vértice de origem até o destino
    if (distancias[destination] == INFINITY) {
        delete[] distancias;
        return -1;
    }
    float result = distancias[destination];
    delete[] distancias;
    return result;
}
    
// A* Algorithm
float GraphList::a_star(int source, int destination, coord* clareiras) {
    PriorityQueue heap(vertices);
    float* distancias = new float[vertices];
    bool* visited = new bool[vertices]();  // Marca os nós visitados

    for (int i = 0; i < vertices; i++) {
        distancias[i] = INFINITY;
    }
    distancias[source] = 0;
    heap.insert(source, heuristic(clareiras[source].x, clareiras[source].y, clareiras[destination].x, clareiras[destination].y ));  // Inserir com heurística

    while (heap.getSize() > 0) {
        int u = heap.extractMin();

        if (u == destination) {
            break;  // Caminho encontrado
        }

        if (visited[u]) {
            continue;
        }
        visited[u] = true;

        Node* current = list[u];
        while (current != nullptr) {
            float newDist = distancias[u] + current->weight;
            
            if (current->weight == 0 && passes > 0) {
                passes--;
            }

            if (distancias[current->data] > newDist) {
                distancias[current->data] = newDist;
                float priority = newDist + heuristic(clareiras[current->data].x,clareiras[current->data].y,  clareiras[destination].x, clareiras[destination].y);
                heap.insert(current->data, priority);
            }
            current = current->next;
        }
    }

    float result = distancias[destination] == INFINITY ? 0 : distancias[destination];
    delete[] distancias;
    delete[] visited;
    return result;
}

// Função heurística de exemplo (deve ser adaptada ao problema)
float GraphList::heuristic(int x1, int y1, int x2, int y2) {
    // Estimar o custo do nó atual ao destino
    return distance(x1, y1, x2, y2);
    return 0;  
}


// Add passes
void GraphList::setPasses(int passes) {
    this->passes = passes;
}
