#include <iostream>
#include <string>

using namespace std;

class biodata {
private:
    string nama;
    int umur;
    string alamat;

public:
    biodata(string name, int age, string add)
        : nama(name), umur(age), alamat(add) {
        cout << "\nConstructor dipanggil\n";
    }

    ~biodata() {
        cout << "\nDestructor dipanggil\n";
    }

    void display() {
        cout << "\nInformasi biodata" << endl;
        cout << "Nama   : " << nama << "\nUmur   : " << umur << "\nAlamat : " << alamat << endl;
    }
};

int main() {
    int u;
    string n, a;

    cout << "Masukkan nama anda   : ";
    getline(cin, n);
    cout << "Masukkan usia anda   : ";
    cin >> u;
    cin.ignore(); 

    cout << "Masukkan alamat anda : ";
    getline(cin, a);

    biodata obj(n, u, a);
    obj.display();
}
