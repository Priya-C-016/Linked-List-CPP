#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node*prev;
    Node*next;
};
Node* head=nullptr;

void insertstart(int data){
    Node* newnode=new Node();
    newnode->data=data;
    if(head==nullptr){
        head=newnode;
        return;
    }
    head->prev=newnode;
    newnode->next=head;
    head=newnode;
}


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

void insertmiddle(int data,int p){
    if(p==1){
        insertstart(data);
        return;
    }
    Node*newnode=new Node();
    newnode->data=data;
    
    Node*temp=head;
    for(int i=1;i<p-1;i++){
        temp=temp->next;
    }
    newnode->next=temp->next;
     newnode->prev=temp;
    temp->next=newnode;
   
   
    
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
        int data,p;cin>>data>>p;
        insertmiddle(data,p);
    }
    print(head);
    return 0;
}
