#include <iostream>
using namespace std;

class Mahasiswa {
protected:
    string nama, jurusan, fakultas;
    int umur;
public:
    Mahasiswa(string n, int u, string j, string f) : nama(n), umur(u), jurusan(j), fakultas(f) {}
    virtual void tampilkanInfo() {
        cout << "\nNama: " << nama << "\nUmur: " << umur << "\nJurusan: " << jurusan << "\nFakultas: " << fakultas << endl;
    }
};

class Aktif : public Mahasiswa {
public:
    Aktif(string n, int u, string j, string f) : Mahasiswa(n, u, j, f) {}
    void tampilkanInfo() override {
        cout << "\nStatus: Mahasiswa Aktif"; Mahasiswa::tampilkanInfo();
    }
};

class Alumni : public Mahasiswa {
public:
    Alumni(string n, int u, string j, string f) : Mahasiswa(n, u, j, f) {}
    void tampilkanInfo() override {
        cout << "\nStatus: Alumni"; Mahasiswa::tampilkanInfo();
    }
};

int main() {
    string nama, jurusan, fakultas, status; int umur;

    for (int i = 0; i < 2; i++) {
        cout << "\nMasukkan Nama: "; getline(cin, nama);
        cout << "Masukkan Umur: "; cin >> umur; cin.ignore();
        cout << "Masukkan Jurusan: "; getline(cin, jurusan);
        cout << "Masukkan Fakultas: "; getline(cin, fakultas);
        cout << "Status (Aktif/Alumni): "; getline(cin, status);

        Mahasiswa* mhs;
        if (status == "Aktif") {
            mhs = new Aktif(nama, umur, jurusan, fakultas);
        } else {
            mhs = new Alumni(nama, umur, jurusan, fakultas);
        }

        mhs->tampilkanInfo();
        delete mhs;
    }
    return 0;
}

