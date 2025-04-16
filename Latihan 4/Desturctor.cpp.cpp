#include <iostream>
using namespace std;

class laptop {
    private:
        string pemilik;
        string merk;

    public:
        laptop(string var1, string var2) {
            pemilik = var1;
            merk = var2;
            cout << "Paket laptop " << merk << " milik " << pemilik << " sudah dikirim" << endl;
        }
};

int main() {
    laptop laptopFadlan("Fadlan", "Asus");
    laptop laptopRisma("Risma", "Acer");
    laptop laptopCarlos("Carlos", "Lenovo");

}
