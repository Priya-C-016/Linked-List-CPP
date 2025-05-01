// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* head=NULL;

void insertbegin(int data){
    Node* newNode=new Node();
    newNode->data=data;
    newNode->next=head;
    head=newNode;
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
}

void insert(int data,int p){
    if(p==1){
        insertbegin(data);
        return;
    }
    Node* newNode=new Node();
    newNode->data=data;
    Node*temp=head;
    for(int i=1;i<p-1;i++){
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
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
    insertbegin(2);
    insertbegin(4);
    insertbegin(8);
    insert(2,1);
    insert(4,1);
    insert(8,2);
    print(head);
    return 0;
}
