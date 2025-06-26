#include <iostream>
using namespace std;

void cetakArray(int arr[], int n) {
    cout << "[ "; 
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "]\n";
}

int partition(int arr[], int low, int high, int pivot) {
    int i = low, j = low;
    while (i <= high) {
        if (arr[i] < pivot) {  // Lewati elemen yang lebih kecil dari pivot
            i++;
        } else {
        	 // Tukar elemen jika lebih besar atau sama dengan pivot
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j++;
        }
    }
    return j - 1; // Posisi akhir pivot
}

void quicksort(int arr[], int low, int high, int n) {
    if (low < high) {
        int pivot = arr[high];
        int pos = partition(arr, low, high, pivot);
        
        cetakArray(arr, n); // Cetak array setiap perubahan
        
        quicksort(arr, low, pos - 1, n); // Urutkan bagian kiri
        quicksort(arr, pos + 1, high, n); // Urutkan bagian kanan
    }
}

int main() {
    int n;
    cout << "Tentukan panjang = ";
    cin >> n;

    int arr[n];
    cout << "Masukkan elemen: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Proses sorting: " << endl;
    quicksort(arr, 0, n - 1, n);
    
    cout << "Array yang telah diurutkan (dari besar hingga kecil) = ";
    cetakArray(arr, n);
    return 0;
}

