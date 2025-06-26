#include <iostream>
using namespace std;

int main() {
    int jumlah;
    cout << "Masukkan jumlah nama: ";
    cin >> jumlah;
    cin.ignore(); // Membersihkan buffer

    string nama[jumlah];

    for (int i = 0; i < jumlah; i++) {
        cout << "Nama ke-" << i + 1 << ": ";
        getline(cin, nama[i]);
    }

    cout << "\nSebelum diurutkan:\n";
    for (int i = 0; i < jumlah; i++) {
        cout << nama[i] << " ";
    }
    cout << endl;

    // Insertion Sort berdasarkan panjang karakter
    for (int i = 1; i < jumlah; i++) {
        string key = nama[i];
        int j = i - 1;
        while (j >= 0 && nama[j].length() > key.length()) {
            nama[j + 1] = nama[j];
            j--;
        }
        nama[j + 1] = key;
    }

    cout << "\nSetelah diurutkan berdasarkan panjang karakter:\n";
    for (int i = 0; i < jumlah; i++) {
        cout << nama[i] << " ";
    }
    cout << endl;

    return 0;
}

