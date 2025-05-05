#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node*prev;
    Node*next;
};
Node* head=nullptr;

void insertend(int data){
    Node* newnode=new Node();
    newnode->data=data;
     newnode->next=nullptr;
    if(head==nullptr){
        head=newnode;
        newnode->prev=nullptr;
        return;
    }
    Node* temp=head;
    while(temp->next){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
}

void reverse(Node* &head){
    Node*curr=head;
    Node*temp=nullptr;
    while(curr){
        temp=curr->prev;
        curr->prev=curr->next;
        curr->next=temp;
        curr=curr->prev;
    }
   if (temp != nullptr) {
        head = temp->prev;
    }

}
void print(Node* head){
    Node* temp=head;
    while(temp){
    cout<<temp->data<<" ";
    temp=temp->next;
    }
}
int main(){
    int n;cout<<"enter the number";
    cin>>n;
    while(n--){
        int data;cin>>data;
        insertend(data);
    }
    print(head);cout<<"\n";
    reverse(head);
    print(head);
    
    return 0;
}
