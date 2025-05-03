#include <iostream>
#include <string>
using namespace std;

class Buku {
public:
    string judul;
    string pengarang;
    int tahun;

    Buku(string j, string p, int t) {
        judul = j;
        pengarang = p;
        tahun = t;
    }

    void tampilkan() {
        cout << "Judul       : " << judul << endl;
        cout << "Pengarang   : " << pengarang << endl;
        cout << "Tahun Terbit: " << tahun << endl;
    }

    ~Buku() {
        cout << "Buku \"" << judul << "\" telah dihapus dari memori.\n";
    }
};

int main() {
    Buku daftar[3] = {
        Buku("Laskar Pelangi", "Andrea Hirata", 2005),
        Buku("Bumi Manusia", "Pramoedya A. Toer", 1980),
        Buku("Harry Potter", "RK Rowling", 1997)
    };

    string cari;
    cout << "Masukkan judul buku yang ingin dicari: ";
    getline(cin, cari);

    bool ditemukan = false;

    for (int i = 0; i < 3; i++) {
        if (daftar[i].judul == cari) {
            cout << "\nBuku ditemukan:\n";
            daftar[i].tampilkan();
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "\nBuku tidak ditemukan.\n";
    }

}

// Kelompok 2
// Fajar Firdaus dan Siti Nur Azizah
