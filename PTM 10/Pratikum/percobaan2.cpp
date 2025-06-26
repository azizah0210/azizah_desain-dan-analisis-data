#include <iostream>
#include <cstring>
using namespace std;

const int N = 100;
int dist[N][N];

void floydWarshall(int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {
    int n;
    cout << "Masukkan jumlah node pada graph: ";
    cin >> n;

    // Inisialisasi semua jarak ke nilai sangat besar (0x3f = 63, untuk inisialisasi dengan memset)
    memset(dist, 0x3f, sizeof(dist));

    // Masukkan jarak dari node ke dirinya sendiri = 0
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }

    cout << "Masukkan jarak antar node:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                cout << "dist[" << i << "][" << j << "]: ";
                cin >> dist[i][j];
            }
        }
    }

    floydWarshall(n);

    cout << "\nMatriks jarak terpendek antar node:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] > 1e6) // nilai besar dari memset
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
