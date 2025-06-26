#include <iostream>

using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = (low - 1);
    
    for (int j = low; j<=high - 1; j++){
        if (arr[j] >= pivot){ //Mengubah menjadi descending
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i+1);
}

void quicksort(int arr[], int low, int high){
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort (arr, low, pi -1);
        quicksort (arr, pi + 1, high);
    }
}

int main(){
    const int size = 5;
    int arr[size];
    
    cout << "Masukkan " << size << " elemen : ";
    for(int i=0; i < size; i++){
        cin >> arr[i];
    }
    cout << endl;
    
    cout<<"Array sebelum diurutkan : ";
	for(int i = 0; i < 5; i++){
		cout << arr[i] << " ";
	} 
    
    quicksort(arr, 0, size - 1);
    
    cout << "\nArray setelah diurutkan : ";
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}



