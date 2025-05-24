#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void insertEndRecursive(Node*& head, int val) {
    if (head == nullptr) {
        head = new Node(val);
        return;
    }
    insertEndRecursive(head->next, val);
}

void insertStartRecursive(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void insertAtPositionRecursive(Node*& head, int val, int pos) {
    if (pos <= 1 || head == nullptr) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        return;
    }
    insertAtPositionRecursive(head->next, val, pos - 1);
}

void printRecursive(Node* head) {
    if (head == nullptr) {
        cout << "\n";
        return;
    }
    cout << head->data << " ";
    printRecursive(head->next);
}

int main() {
    Node* head = nullptr;

    insertStartRecursive(head, 4);        // 4
    insertEndRecursive(head, 5);          // 4 -> 5
    insertEndRecursive(head, 6);          // 4 -> 5 -> 6
    insertAtPositionRecursive(head, 2, 2); // 4 -> 2 -> 5 -> 6

    printRecursive(head);  // Output: 4 2 5 6

    return 0;
}
