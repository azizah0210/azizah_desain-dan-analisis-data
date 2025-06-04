#include <iostream>
using namespace std;

#define MAX 3

class Queue {
private:
    int data[MAX];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue penuh" << endl;
        } else {
            if (isEmpty()) {
                front = 0;
            }
            rear++;
            data[rear] = value;
            cout << "Data " << value << " berhasil ditambahkan ke queue." << endl;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue kosong" << endl;
        } else {
            cout << "Data " << data[front] << " dikeluarkan dari queue." << endl;
            front++;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue kosong" << endl;
        } else {
            cout << "Isi queue: ";
            for (int i = front; i <= rear; i++) {
                cout << data[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Queue q;
    int pilihan, nilai;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Tampilkan\n";
        cout << "4. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                q.enqueue(nilai);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 4);

    return 0;
}

