#include <iostream>
using namespace std;

class Mahasiswa {
public:
    string nama, jurusan, fakultas;
    int umur;

    Mahasiswa(string n, int u, string j, string f)
        : nama(n), umur(u), jurusan(j), fakultas(f) {}

    virtual void tampil() = 0;
};

class MahasiswaAktif : public Mahasiswa {
public:
    MahasiswaAktif(string n, int u, string j, string f)
        : Mahasiswa(n, u, j, f) {}

    void tampil() override {
        cout << "[Mahasiswa Aktif] " << nama << ", " << umur
             << " tahun, " << jurusan << ", " << fakultas << endl;
    }
};

class Alumni : public Mahasiswa {
public:
    Alumni(string n, int u, string j, string f)
        : Mahasiswa(n, u, j, f) {}

    void tampil() override {
        cout << "[Alumni] " << nama << ", " << umur
             << " tahun, " << jurusan << ", " << fakultas << endl;
    }
};

int main() {
    Mahasiswa* m1 = new MahasiswaAktif("Andi", 20, "Informatika", "FST");
    Mahasiswa* m2 = new Alumni("Budi", 25, "Sistem Informasi", "FST");

    m1->tampil();
    m2->tampil();

    delete m1;
    delete m2;
    return 0;
}

