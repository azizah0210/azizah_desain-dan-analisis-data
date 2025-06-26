#include <iostream>
 #include <string>
 using namespace std;
 
 class data {
 private:
     int usia[100];
     double ipk[100];
     string nama[100];
     int hitung;
 
 public:
     data(int a[], string b[], double c[], int j) {
         hitung = j;
         for (int m = 0; m < j; m++) {
             usia[m] = a[m];
             nama[m] = b[m];
             ipk[m] = c[m];
         }
     }
 
     void setnama(string b[], int j) {
         for (int m = 0; m < j; m++)
             nama[m] = b[m];
     }
 
     void setusia(int a[], int j) {
         for (int m = 0; m < j; m++)
             usia[m] = a[m];
     }
 
     void setipk(double c[], int j) {
         for (int m = 0; m < j; m++)
             ipk[m] = c[m];
     }
 
     string getnama(int m) {
         return nama[m];
     }
 
     double getipk(int m) {
         return ipk[m];
     }
 
     int getusia(int m) {
         return usia[m];
     }
 
     int gethitung() {
         return hitung;
     }
 };
 
 int main() {
     int usia[100], a;
     double ipk[100];
     string nama[100], b;
 
     cout << "Masukan jumlah mahasiswa: ";
     cin >> a;
     cin.ignore();
 
     for (int i = 0; i < a; i++) {
         cout << "Masukan data mahasiswa ke - " << i + 1 << endl;
         cout << "Nama: ";
         getline(cin, nama[i]);
         cout << "Usia: ";
         cin >> usia[i];
         cout << "IPK: ";
         cin >> ipk[i];
         cin.ignore();
     }
     
     data mahasiswa(usia, nama, ipk, a);
     
     for (int i = 0; i < mahasiswa.gethitung(); i++) {
     	cout << "\nData Mahasiswa ke - " << i + 1 << endl;
         cout << "Nama: " << mahasiswa.getnama(i) << endl;
         cout << "Usia: " << mahasiswa.getusia(i) << endl;
         cout << "IPK: " << mahasiswa.getipk(i) << endl;
     }
 
     return 0;
 }
