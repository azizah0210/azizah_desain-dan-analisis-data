//sequential search
 
 #include <iostream>
 using namespace std;
 
 int main() 
 {
 	//deklarasi array untuk menyimpan bilangan dan posisinya
 	int nilai[20]; //array untuk menyimpan nilai bilangan
 	int posisi[20]; 
 	int n, i, bil, jmlh = 0;
 	bool ketemu;
 	
 	cout << "Masukkan jumlah deret bilangan = ";
 	cin >> n;
 	cout << endl;
 	
 	
 	//membaca elemen array
 	for (i = 0; i < n; i++) {
 		cout << "Nilai bilangan ke - " << i << " = ";
 		cin >> nilai[i];
 	}
 	
 	//mencetak elemen array
 	cout << "\nDeret Bilangan = ";
 	for (i = 0; i < n; i++) 
 	cout << nilai[i] << " ";
 	
 	cout << "\nMasukkan bilangan yang akan dicari = ";
 	cin >> bil;
 	
 	//melakukan pencarian
 	for(i = 0; i < n; i++) {
 		if (nilai[i] == bil) {
 			ketemu = true;
 			posisi[jmlh] = i;
 			jmlh++;
 		}
 		
 	if(ketemu) {
 		cout << "Bilangan " << bil << " ditemukan sebanyak" << jmlh;
 		cout << "\npada posisi ke = ";
 		for (i = 0; i < jmlh; i++)
 		cout << posisi[i] << " ";
 	}
 	else
 		cout << "maaf, bilangan "<< bil << " tidak ditemukan";
 	getchar();
 }
 }
