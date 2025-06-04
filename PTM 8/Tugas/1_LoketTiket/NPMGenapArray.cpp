#include <iostream>
using namespace std;

#define MAX 5

class Queue {
private:
    string data[MAX];
    int front, rear;

public:
    Queue() {
        front = rear = -1;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(string nama) {
        if (isFull()) {
            cout << "Antrian penuh!\n";
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear++;
        data[rear] = nama;
        cout << nama << " masuk ke antrian.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong!\n";
            return;
        }
        cout << data[front] << " keluar dari antrian.\n";
        front++;
    }

    void display() {
        if (isEmpty()) {
            cout << "Antrian kosong!\n";
            return;
        }
        cout << "Isi antrian:\n";
        for (int i = front; i <= rear; i++) {
            cout << "- " << data[i] << endl;
        }
    }
};

int main() {
    Queue q;
    int pilih;
    string nama;

    do {
        cout << "\nMenu:\n1. Tambah Antrian\n2. Hapus Antrian\n3. Tampilkan Antrian\n4. Keluar\nPilih: ";
        cin >> pilih;
        switch (pilih) {
            case 1:
                cout << "Masukkan nama: ";
                cin >> nama;
                q.enqueue(nama);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
        }
    } while (pilih != 4);

    return 0;
}

