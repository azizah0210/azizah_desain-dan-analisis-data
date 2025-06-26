#include <iostream>
using namespace std;

class Mahasiswa {
private:
    string nama;
    string nim;
    string prodi;

public:
    // Constructor
    Mahasiswa(string n, string i, string p) {
        nama = n;
        nim = i;
        prodi = p;
    }

    // Fungsi untuk menampilkan data
    void tampilkan() {
        cout << "Nama  : " << nama << endl;
        cout << "NIM   : " << nim << endl;
        cout << "Prodi : " << prodi << endl;
    }

    // Fungsi untuk mengambil NIM
    string getNIM() {
        return nim;
    }
};

int main() {
    const int jumlah = 5;

    // Array dari objek Mahasiswa
    Mahasiswa daftar[jumlah] = {
        Mahasiswa("Ari", "23001", "Informatika"),
 		Mahasiswa("Budi", "23002", "Sistem Informasi"),
        Mahasiswa("Cici", "23003", "Teknik Komputer"),
        Mahasiswa("Dina", "23004", "Informatika"),
        Mahasiswa("Eka", "23005", "Teknik Informatika")
    };

    string cariNIM;
    cout << "Masukkan NIM yang ingin dicari: ";
    cin >> cariNIM;

    bool ditemukan = false;
    for (int i = 0; i < jumlah; i++) {
        if (daftar[i].getNIM() == cariNIM) {
            cout << "\nMahasiswa ditemukan:\n";
            daftar[i].tampilkan();
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "Mahasiswa dengan NIM tersebut tidak ditemukan.\n";
    }

}
