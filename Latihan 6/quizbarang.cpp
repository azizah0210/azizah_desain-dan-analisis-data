#include <iostream>
 #include <string>
 using namespace std;
 
 struct barang {
     string nama;
     int harga;
 };
 
 int search(const barang daftar[], string brg) {
     for (int i = 0; i < 5; i++) {
         if (daftar[i].nama == brg) {
             return i;
         }
     }
     return -1;
 }
 
 int main()
 {
     string brg;
     char ulang;
 
     barang daftarbarang[5] = {
         {"Buku", 5000},
         {"Pensil", 1000},
         {"Pulpen", 2000},
         {"Penghapus", 500},
         {"Penggaris", 1500}
     };
 
     do {
         cout << "Masukkan nama barang yang ingin dicari = ";
         cin >> brg;
 
         int index = search(daftarbarang, brg);
         if (index != -1) {
             cout << "Barang " << daftarbarang[index].nama << " ditemukan dengan harga " << daftarbarang[index].harga << endl;
         } else {
             cout << "Maaf, barang " << brg << " tidak ditemukan dalam daftar\n";
         }
 
         cout << "Apakah ingin mencari barang lagi? (y/n): ";
         cin >> ulang;
 
     } while (ulang == 'y' || ulang == 'Y');
 
     cout << "\nTerima kasih!\n";
 }
