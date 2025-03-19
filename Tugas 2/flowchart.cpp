#include <iostream>
using namespace std;

// Fungsi untuk membagi array berdasarkan pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Pilih elemen terakhir sebagai pivot
    int j = low; 

    for (int i = low; i < high; i++) {
        if (arr[i] <= pivot) {  
            // Tukar nilai secara manual tanpa menggunakan swap()
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
        }
    }
    // Tempatkan pivot pada posisi yang benar
    int temp = arr[j];
    arr[j] = arr[high];
    arr[high] = temp;

    return j;  // Kembalikan posisi pivot
}

// Fungsi rekursif Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pos = partition(arr, low, high);
        quickSort(arr, low, pos - 1);   // Urutkan bagian kiri
        quickSort(arr, pos + 1, high);  // Urutkan bagian kanan
    }
}

// Fungsi untuk mencetak array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    
    cout << "Masukkan jumlah elemen: ";
    cin >> n;
    
    int arr[n];
    cout << "Masukkan elemen array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Array sebelum diurutkan: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "Array setelah diurutkan: ";
    printArray(arr, n);

    return 0;
}

