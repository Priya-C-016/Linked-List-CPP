// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* head=NULL;
void insert(int data){
    Node*newNode=new Node();
    newNode->data=data;
    newNode->next=NULL;
    if(head==NULL){
        head=newNode;
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode=head;
}

int middle(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow->data;
}
void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"\n";
}
int main() {
   int n;
   cout<<"Enter the number";
   cin>>n;
   while(n--){
       int data;cin>>data;
       insert(data);
   }
   print(head);
   cout<<middle(head);
   

    return 0;
}
