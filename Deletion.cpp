// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* head=NULL;
void deletestart(){
    if(head==NULL){
        cout<<"empty";return;
    }
    Node* temp=head;
    head=temp->next;
    temp=NULL;
} 
void insertend(int data){
    Node* newNode=new Node();
    newNode->data=data;
    newNode->next=NULL;
    if(head==NULL){
        head=newNode;
        return;
    }
    Node* temp=head;
    while(temp->next){
        temp=temp->next;
    }
    temp->next=newNode;
    temp=head;
}
void deleteend(){
    if(head==NULL){
        cout<<"linked list is empty";
        return;
    }
    if(head->next==NULL){
        delete head;head=NULL;return;
    }
    Node * temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;
}

void deleteMiddle(int p){
    if(head==NULL){
        cout<<"empty";
        return;
    }
    if(p==1){
        deletestart();
        return;
    }
    Node* temp=head;
    for(int i=1;i<p-1;i++){
        temp=temp->next;
    }
    temp->next=temp->next->next;
    temp=head;
    
} 

void print(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main() {
    insertend(2);
    insertend(4);
    insertend(8);
    print(head);cout<<"\n";
    // deleteend();
    // print(head);
    deletestart();
    print(head);cout<<"\n";
    deleteMiddle(2);
    print(head);
    return 0;
}
