#include <iostream>
using namespace std;

// Struktur node binary tree
struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Fungsi Preorder Traversal: Root -> Left -> Right
void preorderTraversal(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Fungsi Inorder Traversal: Left -> Root -> Right
void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    // Membuat tree sesuai struktur
    Node* A = new Node('A');
    Node* B = new Node('B');
    Node* C = new Node('C');
    Node* D = new Node('D');
    Node* E = new Node('E');

    A->left = B;
    A->right = C;
    B->left = D;
    B->right = E;

    // Menampilkan hasil traversal
    cout << "Preorder Traversal: ";
    preorderTraversal(A);
    cout << endl;

    cout << "Inorder Traversal: ";
    inorderTraversal(A);
    cout << endl;

    return 0;
}

