#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define INF 999

int minDistance(vector<int>& dist, vector<bool>& sptSet, int n) {
    int min = INF, min_index;

    for (int v = 0; v < n; v++)
        if (!sptSet[v] && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printPath(vector<int>& parent, int j) {
    if (parent[j] == -1) {
        cout << j + 1; // Ditambah 1 agar sesuai penomoran kota (1-indexed)
        return;
    }
    printPath(parent, parent[j]);
    cout << "--->" << j + 1;
}

void dijkstra(vector< vector<int> >& graph, int src) {
    int n = graph.size();
    vector<int> dist(n, INF);      // Jarak terpendek ke setiap kota
    vector<bool> sptSet(n, false); // Kota yang sudah diproses
    vector<int> parent(n, -1);     // Untuk menyimpan jalur

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, sptSet, n);
        sptSet[u] = true;

        for (int v = 0; v < n; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Tampilkan hasil
    cout << "\nCost List :\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << graph[i][j] << " ";
        cout << endl;
    }

    cout << "\nJalur Terpendek :\n";
    printPath(parent, n - 1); // dari 0 ke n-1
    cout << "\n\nMinimum Cost : " << dist[n - 1] << endl;
}

int main() {
    int n;
    cout << "Masukkan Jumlah Kota : ";
    cin >> n;

    vector< vector<int> > graph(n, vector<int>(n));
    cout << "Nilai Cost Matrix\n";
    for (int i = 0; i < n; i++) {
        cout << "Cost Element Baris ke-: " << i + 1 << endl;
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    dijkstra(graph, 0); // mulai dari kota ke-1 (indeks 0)
    return 0;
}

