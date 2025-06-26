#include <iostream> // Input/output
using namespace std;

class contoh {
    private:
        int nilai; // Variabel privat

    public:
        contoh(int n) { // Konstruktor
            nilai = n;
        }

        int getNum() { // Ambil nilai
            return nilai;
        }

        // Destructor opsional
};

int main() {
    contoh obj(10); // Buat objek
    cout << "Nilai yang dimasukkan: " << obj.getNum() << endl; // Cetak nilai
    return 0;
}

