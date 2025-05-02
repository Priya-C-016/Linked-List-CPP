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

int intersection(Node* head1,Node* head2){
   Node * t1=head1;
        Node * t2=head2;
        while(t1!=NULL && t2!=NULL){
            if(t2->next==t1){
                return t1->data;
            }
            if(t1->next==t2){
                return t2->data;
            }
            if(t1==t2)return t1->data;
            t1=t1->next;
            t2=t2->next;
        }
        
        return -1;
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
    head2->next = head1->next->next;
    cout << "List 1: ";
    print(head1);
    cout << "List 2: ";
    print(head2);
    
    // insert(head,12);
    cout<<intersection(head1, head2);
    

    return 0;
}
