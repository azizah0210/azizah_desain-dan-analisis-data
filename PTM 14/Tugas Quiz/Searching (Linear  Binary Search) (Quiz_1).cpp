#include <iostream>
using namespace std;

// Fungsi binary search
int binarySearch(int data[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (data[mid] == target) {
            return mid;  // Mengembalikan index jika ditemukan
        } else if (data[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;  // Jika tidak ditemukan
}

int main() {
    int data[] = {11, 22, 33, 44, 55, 66, 77};
    int size = sizeof(data) / sizeof(data[0]);
    int target;

    cout << "Masukkan angka yang ingin dicari: ";
    cin >> target;

    int index = binarySearch(data, size, target);

    if (index != -1) {
        cout << "Data ditemukan pada index ke-" << index << endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }

    return 0;
}

