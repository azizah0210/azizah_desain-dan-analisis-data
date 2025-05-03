#include <iostream>
using namespace std;

// Struktur data buku
struct Buku {
    string judul;
    int rak;
};

// Fungsi bubble sort untuk mengurutkan buku berdasarkan judul
void urutkanBuku(Buku buku[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (buku[j].judul > buku[j + 1].judul) {
                // Tukar posisi
                Buku temp = buku[j];
                buku[j] = buku[j + 1];
                buku[j + 1] = temp;
            }
        }
    }
}

// Binary search untuk mencari judul buku
int cariBuku(Buku buku[], int n, string target) {
    int kiri = 0, kanan = n - 1;
    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;
        if (buku[tengah].judul == target) {
            return tengah;
        } else if (buku[tengah].judul < target) {
            kiri = tengah + 1;
        } else {
            kanan = tengah - 1;
        }
    }
    return -1; // Tidak ditemukan
}
int main() {
    // Daftar buku
    Buku daftarBuku[] = {
        {"Bahasa C++ Dasar", 3},
        {"Algoritma Pemrograman", 1},
        {"Struktur Data", 2},
        {"Jaringan Komputer", 4},
        {"Database Lanjut", 5}
    };

    int jumlahBuku = sizeof(daftarBuku) / sizeof(daftarBuku[0]);

    // Urutkan buku secara manual
    urutkanBuku(daftarBuku, jumlahBuku);

    // Input dari user
    string judulDicari;
    cout << "Masukkan judul buku yang dicari: ";
    getline(cin, judulDicari);

    // Cari menggunakan binary search
    int index = cariBuku(daftarBuku, jumlahBuku, judulDicari);

    // Tampilkan hasil
    if (index != -1) {
        cout << "Buku ditemukan di rak nomor: " << daftarBuku[index].rak << endl;
    } else {
        cout << "Buku tidak ditemukan di perpustakaan." << endl;
    }

}
