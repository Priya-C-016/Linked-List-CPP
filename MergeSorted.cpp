#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to insert a node at the end
void insert(Node* &head, int data) {
    Node* newNode = new Node{data, NULL};
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

// Function to print linked list
void print(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}
Node* merge(Node* head1,Node* head2){
    Node dummy;
    Node* tail=&dummy;
    while(head1!=NULL && head2!=NULL){
        if(head1->data<=head2->data){
            tail->next=head1;
            head1=head1->next;
        }else{
            tail->next=head2;
            head2=head2->next;
        }
        tail=tail->next;
    }
    if(head1)tail->next=head1;
    if(head2)tail->next=head2;
    return dummy.next;
}

int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;

    int n1, n2, data;

    cout << "Enter number of elements in list 1: ";
    cin >> n1;
    cout << "Enter " << n1 << " sorted elements:\n";
    while (n1--) {
        cin >> data;
        insert(head1, data);
    }

    cout << "Enter number of elements in list 2: ";
    cin >> n2;
    cout << "Enter " << n2 << " sorted elements:\n";
    while (n2--) {
        cin >> data;
        insert(head2, data);
    }

    cout << "List 1: ";
    print(head1);
    cout << "List 2: ";
    print(head2);

    Node* merged = merge(head1, head2);
    cout << "Merged Sorted List: ";
    print(merged);

    return 0;
}
