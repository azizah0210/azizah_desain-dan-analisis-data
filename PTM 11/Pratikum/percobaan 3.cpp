#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <utility> // <-- untuk pair

using namespace std;

typedef pair<int, int> pii;

// Fungsi Dijkstra
void dijkstra(int start, vector<vector<pair<int, int>>> &graph, vector<int> &dist, vector<int> &prev)

    int n = graph.size();
    dist.assign(n, INT_MAX);
    prev.assign(n, -1);
    dist[start] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (u_dist > dist[u]) continue;

        for (auto &neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                prev[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}

// Fungsi untuk menampilkan rute
void printPath(int target, const vector<int> &prev) {
    if (target == -1) return;
    printPath(prev[target], prev);
    cout << target << " ";
}

// Fungsi utama
int main() {
    int n = 7; // node 1 sampai 6 (0 tidak digunakan)
    vector<vector<pii>> graph(n);

    // Tambahkan sisi sesuai gambar
    graph[1].push_back({2, 7});
    graph[1].push_back({3, 9});
    graph[1].push_back({6, 14});

    graph[2].push_back({1, 7});
    graph[2].push_back({3, 10});
    graph[2].push_back({4, 15});

    graph[3].push_back({1, 9});
    graph[3].push_back({2, 10});
    graph[3].push_back({6, 2});
    graph[3].push_back({4, 11});

    graph[4].push_back({2, 15});
    graph[4].push_back({3, 11});
    graph[4].push_back({5, 6});

    graph[5].push_back({4, 6});
    graph[5].push_back({6, 9});

    graph[6].push_back({1, 14});
    graph[6].push_back({3, 2});
    graph[6].push_back({5, 9});

    vector<int> dist, prev;
    int start = 1;

    dijkstra(start, graph, dist, prev);

    cout << "Rute terpendek dari simpul " << start << " ke semua simpul lainnya:\n";
    for (int i = 1; i < n; ++i) {
        cout << "Ke simpul " << i << " (jarak = " << dist[i] << "): ";
        printPath(i, prev);
        cout << endl;
    }

    return 0;
}

