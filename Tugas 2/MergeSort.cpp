#include <iostream>
#include <vector>
using namespace std;

void printList(const vector<int>& arr) {
    cout << "[";
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << ", ";
    }
    cout << "]\n";
}

void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);
    
    int i = 0, j = 0, k = left;
    while (i < leftArr.size() && j < rightArr.size()) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }
    while (i < leftArr.size()) arr[k++] = leftArr[i++];
    while (j < rightArr.size()) arr[k++] = rightArr[j++];
    
    cout << "Menggabungkan List ";
    printList(vector<int>(arr.begin() + left, arr.begin() + right + 1));
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        cout << "Memecah List ";
        printList(vector<int>(arr.begin() + left, arr.begin() + right + 1));
        
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    cout << "Input jumlah data: ";
    cin >> n;
    vector<int> arr(n);
    
    cout << "Masukkan data: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    mergeSort(arr, 0, n - 1);
    
    cout << "Hasil akhir: ";
    printList(arr);
    
    return 0;
}
