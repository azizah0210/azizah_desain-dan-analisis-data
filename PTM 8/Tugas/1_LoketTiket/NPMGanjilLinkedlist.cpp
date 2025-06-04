#include <iostream>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = NULL;
    }

    void enqueue(string nama) {
        Node* baru = new Node{nama, NULL};
        if (rear == NULL) {
            front = rear = baru;
        } else {
            rear->next = baru;
            rear = baru;
        }
        cout << nama << " masuk ke antrian.\n";
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Antrian kosong.\n";
            return;
        }
        Node* hapus = front;
        front = front->next;
        if (front == NULL) rear = NULL;
        cout << hapus->nama << " keluar dari antrian.\n";
        delete hapus;
    }

    void display() {
        if (front == NULL) {
            cout << "Antrian kosong.\n";
            return;
        }
        cout << "Isi antrian:\n";
        Node* temp = front;
        while (temp != NULL) {
            cout << "- " << temp->nama << endl;
            temp = temp->next;
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

