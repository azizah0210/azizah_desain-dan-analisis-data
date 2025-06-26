#include <iostream>
#include <vector>

using namespace std;

//kelas untuk merepresentasikan graph

class Graf {
	private:
		int jumlahSimpul; //jumlah simpul dalam graf
		vector<vector<int> > matriksKetetanggaan; //Matriks Tetangga
		
	public:
		//konstruktor
	Graf (int simpul)
		:jumlahSimpul (simpul){
		
		//inisialisasi matriks ketetanggan dnegan nol
		for(int i=0; i < simpul; ++i ){
			vector<int> baris(simpul,0);
			matriksKetetanggaan.push_back(baris);
		}

	}
	

//Menambahkan sisi (edge) ke dalam graf
void tambahSisi (int u, int v){
	if (u >= 0 && u < jumlahSimpul && v >= 0 && v <jumlahSimpul){
		matriksKetetanggaan[u][v] = 1;
		matriksKetetanggaan[v][u] = 1;
	}else
	cout << "Sisi tidak valid!" << endl;
}

//Menghapus sisi (edge) dari graf
void hapusSisi (int u, int v){
	if (u >= 0 && u < jumlahSimpul && v >= 0 && v < jumlahSimpul){
		matriksKetetanggaan[u][v] = 0;
		matriksKetetanggaan[v][u] = 0; //untuk graf undirected, komen ini jika directed
	}else {
		cout << "Sisi tidak valid!";
	}
}

//Menampilkan matriks Ketetanggaan
void tampilkan(){
	for(int i=0; i < jumlahSimpul; i++){
		for (int j = 0; j < jumlahSimpul; j++){
			cout << matriksKetetanggaan [i][j] << "  ";
		}
		cout << endl;
	}
}
};


int main (){
	int simpul=5;
	Graf g(simpul);
	
	//Menambahkan sisi-sisi ke dalam grad
	
	g.tambahSisi(0,1);
	g.tambahSisi(0,4);
	g.tambahSisi(1,2);
	g.tambahSisi(1,4);
	g.tambahSisi(2,3);
	g.tambahSisi(3,4);
	g.tambahSisi(1,3); 
	
	//Menampilkan 
	cout << "Matriks Ketetanggaan:" << endl;
	g.tampilkan();
	
	//Menghapus sisi dari graf
	g.hapusSisi (1,3);
	cout << "Matriks Ketetanggan setelah menghapus sisi antara 1 & 3:" << endl;
	g.tampilkan();
	
	return 0;
}
