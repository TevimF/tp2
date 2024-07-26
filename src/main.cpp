
#include "../include/PriorityQueue.hpp"
#include "../include/MinHeap.hpp"
#include "../include/Graph.hpp"
#include <iostream>

using namespace std;


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
    grafo.setPasses(q_passes);

    // debug: 
    /*
    grafo.printGraph();
    printf("\nEnergia: %d", s_energia);
    printf("\nPasses: %d", q_passes);
    cout << endl;
    */
   float menor_caminho_dijkl = grafo.dijkstra_list(0, n_clareiras - 1);
   if (menor_caminho_dijkl <= s_energia || menor_caminho_dijkl == -1) {
        cout << "1 ";
   } else {
        cout << "0 ";
   }
float menor_caminho_a_star = grafo.a_star(0, n_clareiras - 1, clareiras);
    if (menor_caminho_a_star <= s_energia) {
        cout << "1";
    } else {
        cout << "0";
    }
   

    return 0;
   
    

}
