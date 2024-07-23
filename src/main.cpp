#include <bits/stdc++.h>
using namespace std;

#define INFINITO 1000000

// Definição da estrutura para armazenar pares de inteiros
struct par_int {
    int x;
    int y;
    void imprimir() const {
        cout << this->x << " " << this->y << endl;
    }
};

// Estrutura para armazenar a distância, vértice, passes restantes e custo estimado
struct estado {
    int vertice;
    float dist;
    int passes;
    float heuristica;
    bool operator>(const estado& other) const {
        return (dist + heuristica) > (other.dist + other.heuristica);
    }
    void imprimir() const {
        cout << this->vertice << " " << this->dist << " " << this->passes << " " << this->heuristica << endl;
    }
};

vector<par_int> clareiras;
vector<par_int> trilhas;
vector<par_int> portais;
vector<vector<pair<int, float>>> adj; // Lista de adjacências para o grafo
vector<vector<int>> portal_connections; // Lista de conexões dos portais

// Função para calcular a distância entre dois pontos
float distancia_vertices(par_int a, par_int b) {
    int x1 = a.x, y1 = a.y;
    int x2 = b.x, y2 = b.y;
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

// Função heurística para o A*
float heuristica(int u, int objetivo) {
    return distancia_vertices(clareiras[u], clareiras[objetivo]);
}

// Função de Dijkstra para encontrar o caminho mais curto considerando passes
vector<float> dijkstra(int start, int q_passes) {
    int n = clareiras.size();
    vector<vector<float>> dist(n, vector<float>(q_passes + 1, INFINITO));
    priority_queue<estado, vector<estado>, greater<estado>> pq;
    
    dist[start][q_passes] = 0;
    pq.push({start, 0, q_passes, heuristica(start, n - 1)});

    while (!pq.empty()) {
        int u = pq.top().vertice;
        float d = pq.top().dist;
        int passes = pq.top().passes;
        pq.pop();

        if (d > dist[u][passes]) continue;

        // Verificar conexões normais
        for (const auto& edge : adj[u]) {
            int v = edge.first;
            float weight = edge.second;

            if (dist[u][passes] + weight < dist[v][passes]) {
                dist[v][passes] = dist[u][passes] + weight;
                pq.push({v, dist[v][passes], passes, heuristica(v, n - 1)});
            }
        }

        // Verificar se o vértice pode usar portais
        if (passes > 0) {
            for (int v : portal_connections[u]) {
                if (dist[u][passes] < dist[v][passes - 1]) {
                    dist[v][passes - 1] = dist[u][passes]; // Usando o portal com custo zero
                    pq.push({v, dist[v][passes - 1], passes - 1, heuristica(v, n - 1)});
                }
            }
        }
    }

    // Encontrar a menor distância com qualquer número de passes restantes
    vector<float> result(n, INFINITO);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= q_passes; ++j) {
            result[i] = min(result[i], dist[i][j]);
        }
    }

    return result;
}

// Algoritmo A* para encontrar o caminho mais curto considerando passes
bool astar(int start, int objetivo, int q_passes) {
    int n = clareiras.size();
    vector<vector<float>> dist(n, vector<float>(q_passes + 1, INFINITO));
    priority_queue<estado, vector<estado>, greater<estado>> pq;
    
    dist[start][q_passes] = 0;
    pq.push({start, 0, q_passes, heuristica(start, objetivo)});

    while (!pq.empty()) {
        int u = pq.top().vertice;
        float d = pq.top().dist;
        int passes = pq.top().passes;
        pq.pop();

        if (u == objetivo) return true;
        if (d > dist[u][passes]) continue;

        // Verificar conexões normais
        for (const auto& edge : adj[u]) {
            int v = edge.first;
            float weight = edge.second;

            if (dist[u][passes] + weight < dist[v][passes]) {
                dist[v][passes] = dist[u][passes] + weight;
                pq.push({v, dist[v][passes], passes, heuristica(v, objetivo)});
            }
        }

        // Verificar se o vértice pode usar portais
        if (passes > 0) {
            for (int v : portal_connections[u]) {
                if (dist[u][passes] < dist[v][passes - 1]) {
                    dist[v][passes - 1] = dist[u][passes]; // Usando o portal com custo zero
                    pq.push({v, dist[v][passes - 1], passes - 1, heuristica(v, objetivo)});
                }
            }
        }
    }

    return false;
}

int main() {
    int n_clareiras, m_trilhas, k_portais, s_energia, q_passes;
    cin >> n_clareiras >> m_trilhas >> k_portais;

    clareiras.resize(n_clareiras);
    trilhas.resize(m_trilhas);
    portais.resize(k_portais);
    adj.resize(n_clareiras);
    portal_connections.resize(n_clareiras);

    for (int i = 0; i < n_clareiras; i++) {
        int x, y;
        cin >> x >> y;
        clareiras[i] = {x, y};
    }

    for (int i = 0; i < m_trilhas; i++) {
        int u, v;
        cin >> u >> v;
        float dist = distancia_vertices(clareiras[u], clareiras[v]);
        adj[u].emplace_back(v, dist);
        adj[v].emplace_back(u, dist); // Se o grafo é não direcionado
    }

    for (int i = 0; i < k_portais; i++) {
        int x, y;
        cin >> x >> y;
        // Adicionar portais na lista de conexões
        portal_connections[x].push_back(y);
        portal_connections[y].push_back(x);
    }

    cin >> s_energia >> q_passes;

    // Executar Dijkstra a partir do primeiro clareira (index 0)
    vector<float> dist_dijkstra = dijkstra(0, q_passes);

    // Executar A* a partir do primeiro clareira (index 0) para o objetivo (último clareira, index n_clareiras - 1)
    bool caminho_dijkstra = dist_dijkstra[n_clareiras - 1] <= s_energia;
    bool caminho_astar = astar(0, n_clareiras - 1, q_passes);

    // Imprimir informações
    /*
    cout << "clareiras = " << n_clareiras << endl;
    cout << "trilhas = " << m_trilhas << endl;
    cout << "portais = " << k_portais << endl;
    for (const auto& i : clareiras) {
        cout << "clareira: ";
        i.imprimir();
    }
    for (const auto& i : trilhas) {
        cout << "trilha: ";
        i.imprimir();
    }
    for (const auto& i : portais) {
        cout << "portal: ";
        i.imprimir();
    }
    cout << "energia: " << s_energia << endl;
    cout << "passes: " << q_passes << endl;

    cout << "Resultados:" << endl;
    if (caminho_dijkstra && caminho_astar) {
        cout << "Existe um caminho para Dijkstra e A*." << endl;
    } else if (caminho_dijkstra) {
        cout << "Existe um caminho apenas para Dijkstra." << endl;
    } else if (caminho_astar) {
        cout << "Existe um caminho apenas para A*." << endl;
    } else {
        cout << "Não existe um caminho para nenhum dos algoritmos." << endl;
    }
    */
   if (caminho_dijkstra){
    cout << 1 << " ";
   }else{
    cout << 0 << " ";
   }
   if (caminho_astar){
    cout << 1 ;
   }else{
    cout << 0 ;
   }
    

    return 0;
}
