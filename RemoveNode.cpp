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

}
void deletev(int p){
    if(head==NULL){
        cout<<"linked list is empty";
        return;
    }
    if(p==1){
        Node* temp=head;
        head=temp->next;delete temp;
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
   deletev(2);
   print(head);
  
   

    return 0;
}
