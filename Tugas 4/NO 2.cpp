#include <iostream>
#include <string>
using namespace std;

class Kontak {
private:
    string nama;
    string nomor;

public:
    // Constructor
    Kontak(string n, string no) {
        nama = n;
        nomor = no;
        cout << "Kontak berhasil ditambahkan\n";
    }

    // Method untuk menampilkan data kontak
    void tampilkan() {
        cout << "Nama   : " << nama << endl;
        cout << "Nomor Telepon : " << nomor << endl;
    }

    // Destructor
    ~Kontak() {
        // Optional: tampilkan pesan saat objek dihancurkan
        // cout << "Kontak " << nama << " dihapus.\n";
    }
};

int main() {
    const int MAKS_KONTAK = 10;
    Kontak* daftar[MAKS_KONTAK]; // Array pointer ke objek Kontak
    int jumlah = 0;
    char lagi;

    cout << "Masukkan kontak (maksimal 10 kontak)\n";

    do {
        if (jumlah >= MAKS_KONTAK) {
            cout << "Batas maksimum kontak tercapai.\n";
            break;
        }

        string nama, nomor;
        cout << "\nMasukkan nama kontak ke - " << jumlah + 1 << " : ";
        getline(cin, nama);
        cout << "Masukkan nomor telepon kontak ke - " << jumlah + 1 << " : ";
        getline(cin, nomor);

        // Membuat objek Kontak baru
        daftar[jumlah] = new Kontak(nama, nomor);
        jumlah++;

        cout << "Tambahkan kontak lagi? (y/n): ";
        cin >> lagi;
        cin.ignore(); // Membersihkan newline di buffer
    } while (lagi == 'y' || lagi == 'Y');

    // Tampilkan daftar kontak
    cout << "\nDaftar Kontak:\n";
    for (int i = 0; i < jumlah; i++) {
        cout << "\nKontak ke - " << i + 1 << endl;
        daftar[i]->tampilkan();
        cout << "----------------------------\n";
    }

    // Hapus semua kontak (panggil destructor)
    for (int i = 0; i < jumlah; i++) {
        delete daftar[i];
    }

    return 0;
}

