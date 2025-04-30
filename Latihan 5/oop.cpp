#include <iostream>
#include <string>
using namespace std;

class hitung {
private:
    float a, b;

public:
    void setno1(float num1) {
        a = num1;
    }

    void setno2(float num2) {
        b = num2;
    }

    float tambah() {
        return a + b;
    }

    float kurang() {
        return a - b;
    }

    float kali() {
        return a * b;
    }

    float bagi() {
        return a / b;
    }
};

int main() {
float no1, no2;
    hitung Hitung;

    cout << "Masukkan angka pertama : ";
    cin >> no1;
    Hitung.setno1(no1);

    cout << "Masukkan angka kedua : ";
    cin >> no2;
    Hitung.setno2(no2);

    cout << "\nHasil penambahan : " << Hitung.tambah();
    cout << "\nHasil pengurangan : " << Hitung.kurang();
    cout << "\nHasil perkalian : " << Hitung.kali();
    cout << "\nHasil pembagian : " << Hitung.bagi(); 
}













