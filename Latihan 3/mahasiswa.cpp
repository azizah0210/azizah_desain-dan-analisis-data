#include <iostream>
using namespace std;

class Mahasiswa {
    public:
        string nama;
        int NPM;

    public:
        void setNama(string n) {
            nama = n;
        }

        void setNPM(int p) {
            NPM = p;
        }

        string getNama() {
            return nama;
        }

        int getNPM() {
            return NPM;
        }
};

int main() { 
    Mahasiswa mhsw;
    string inputNama;
    int inputNPM;

    cout << "Masukkan nama: ";
    getline(cin, inputNama);
    mhsw.setNama(inputNama);

    cout << "Masukkan NPM: ";
    cin >> inputNPM;
    mhsw.setNPM(inputNPM);


    cout << "\nData Mahasiswa:\n";
    cout << "Nama : " << mhsw.getNama() << endl;
    cout << "NPM  : " << mhsw.getNPM() << endl;

    return 0;
}
