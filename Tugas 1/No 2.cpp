#include <iostream>
using namespace std;

// Insertion Sort
void insertionSort(string arr[], int n) {
    for (int i = 1; i < n; i++) {
        string key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Bubble Sort
void bubbleSort(string arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Selection Sort
void selectionSort(string arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        string temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main() {
    int n;
    cout << "Masukkan jumlah buku: ";
    cin >> n;

    string books[100]; // Maksimal 100 buku
    cout << "Masukkan judul buku:\n";
    for (int i = 0; i < n; i++) {
        cin >> books[i]; // Menggunakan cin untuk input judul buku
    }

    // Melakukan tiga jenis sorting (urutan tidak mempengaruhi hasil akhir)
    insertionSort(books, n);
    bubbleSort(books, n);
    selectionSort(books, n);

    // Menampilkan hasil sorting
    cout << "\nJudul buku setelah diurutkan :\n";
    for (int i = 0; i < n; i++) {
        cout << books[i] << endl;
    }

    return 0;
}

