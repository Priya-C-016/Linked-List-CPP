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

void deletestart(){
    Node* temp=head;
    head=temp->next;
    delete temp;
}
void deleteend(){
    if(head==nullptr){
        cout<<"empty";
        return;
    }
    Node* temp=head;
    while(temp->next){
        temp=temp->next;
    }
    temp->prev->next=nullptr;delete temp;
}
void deletemiddle(int p){
    if(p==1){
        deletestart();
        return;
    }
    Node* temp=head;
    for(int i=1;i<p;i++){
        temp=temp->next;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    delete temp;
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
    deletemiddle(2);
    print(head);
    
    return 0;
}
