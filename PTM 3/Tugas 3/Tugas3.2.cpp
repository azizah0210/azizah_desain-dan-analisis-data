#include <iostream>
#include <vector>
using namespace std;

class Buku {
private:
    string judul;
    string nama;
    string npm;

public:
    Buku(string j, string n, string np) {
        judul = j;
        nama = n;
        npm = np;
    }

    void tampilkanInfo() {
        cout << "Judul Buku: " << judul << endl;
        cout << "Nama Peminjam: " << nama << endl;
        cout << "NPM: " << npm << endl;
    }

    string getJudul() {
        return judul;
    }
};

class Perpustakaan {
private:
    vector<Buku> koleksiBuku;

public:
    void tambahBuku(Buku buku) {
        koleksiBuku.push_back(buku);
    }

    void tampilkanSemuaBuku() {
        for (size_t i = 0; i < koleksiBuku.size(); i++) {
            cout << "\nBuku " << i + 1 << ": " << endl;
            koleksiBuku[i].tampilkanInfo();
        }
    }

    void cariBuku(string judul) {
        bool ditemukan = false;
        for (size_t i = 0; i < koleksiBuku.size(); i++) {
            if (koleksiBuku[i].getJudul() == judul) {
                cout << "\nBuku ditemukan: " << endl;
                koleksiBuku[i].tampilkanInfo();
                ditemukan = true;
                break;
            }
        }
        if (!ditemukan) {
            cout << "\nBuku tidak ditemukan." << endl;
        }
    }
};

int main() {
    Perpustakaan perpustakaan;
    int jumlah;
    string judul, nama, npm;
    
    cout << "Masukkan jumlah buku yang ingin ditambahkan: ";
    cin >> jumlah;
    cin.ignore();
    
    for (int i = 0; i < jumlah; i++) {
        cout << "\nMasukkan data buku ke-" << i + 1 << ":" << endl;
        cout << "Judul Buku: ";
        getline(cin, judul);
        cout << "Nama Peminjam: ";
        getline(cin, nama);
        cout << "NPM: ";
        getline(cin, npm);
        
        perpustakaan.tambahBuku(Buku(judul, nama, npm));
    }

    cout << "\nDaftar Buku di Perpustakaan:" << endl;
    perpustakaan.tampilkanSemuaBuku();

    cout << "\nMasukkan judul buku yang ingin dicari: ";
    getline(cin, judul);
    perpustakaan.cariBuku(judul);

    return 0;
}
