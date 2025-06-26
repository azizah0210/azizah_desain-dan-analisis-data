#include <iostream>
using namespace std;

void bubsort(int arr[], int n) //Deklarasi fungsi bubsort, menerima array (arr[]) dan jumlah elemen (n).
{
	int i, j, tmp;
	//proses Bubble Sort
	for (i = 0; i < n; i++) {
		//proses sorting fase
		for(j = 0; j < n - i- 1; j++) {
			//proses penukaran
			if(arr[j] < arr[j + 1]) {
				//arr = Array, tmp = data sementara/ data sekarang
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
   
   int main ()
{
	int array[100], n, i, j;
	cout << "Masukkan banyak elemen = ";
	cin >> n;
	cout << "Masukkan nilai = \n";
	
	//Lopping mengambil nilai sebanyak 'n'
	for (i = 0; i < n; i++) {
		cin >> array[i];
	}
	
	bubsort(array, n);
	
	cout << "Hasil pengurutan dengan algoritma bubble sort = \n";
	
	for (i = 0; i < n; i++){
		cout << array[i] << " ";
	}
	cout << "\n";
	
}
