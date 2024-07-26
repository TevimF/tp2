
#include "../include/PriorityQueue.hpp"
#include "../include/MinHeap.hpp"
#include "../include/Graph.hpp"
#include <iostream>

using namespace std;
struct coord {
    int x, y;
};
float distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}


int main() {
    int n_clareiras, m_trilhas, k_portais, s_energia, q_passes;
    cin >> n_clareiras >> m_trilhas >> k_portais;

    coord clareiras[n_clareiras]; // vertices
    GraphList grafo(n_clareiras);

    for (int i = 0; i < n_clareiras; i++) {
        int x, y;
        cin >> x >> y;
        clareiras[i] = {x, y};
    }

    for (int i = 0; i < m_trilhas; i++) {
        int u, v;
        cin >> u >> v;
        float distancia = distance(clareiras[u].x, clareiras[u].y , clareiras[v].x, clareiras[v].y);
        grafo.addEdge(u, v, distancia);
    }

    for (int i = 0; i < k_portais; i++) {
        int u, v;
        cin >> u >> v;
        grafo.addEdge(u, v, 0);
    }

    cin >> s_energia >> q_passes;

    // debug: 
    /*
    grafo.printGraph();
    printf("\nEnergia: %d", s_energia);
    printf("\nPasses: %d", q_passes);
    cout << endl;
    */
    

}
