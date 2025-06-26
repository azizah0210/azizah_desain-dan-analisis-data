#include <iostream>
#include <algorithm> // Untuk std::binary_search
using namespace std;

int main() {
    int data[] = {6, 12, 18, 24};
    int jumlah = sizeof(data) / sizeof(data[0]);

    int dicari;
    cout << "Masukkan data yang dicari: ";
    cin >> dicari;

    // Gunakan binary_search dari STL
    bool ditemukan = binary_search(data, data + jumlah, dicari);

    if (ditemukan) {
        // Gunakan find untuk mengetahui indeks
        int* pos = find(data, data + jumlah, dicari);
        int indeks = pos - data;
        cout << "Bilangan ditemukan di indeks " << indeks << endl;
    } else {
        cout << "Bilangan tidak ditemukan." << endl;
    }

   
}



