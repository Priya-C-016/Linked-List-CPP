#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* head=NULL;
void insert(int data){
    Node* newnode=new Node();
    newnode->data=data;
    newnode->next=head;
    head=newnode;
}
void deleted(int val){
    if(head->data==val){
        Node* temp=head;
        head=head->next;
        delete temp;
        return;
    } 
    Node * temp=head;
    while (temp->next != NULL && temp->next->data != val) {
        temp = temp->next;
    }
    if(temp->next!=nullptr){
        Node* d=temp->next;
        temp->next=temp->next->next;
        delete d;
    }
    
    
}
void print(Node* head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main(){
    int n;cin>>n;
    while(n--){
        int data;cin>>data;
        insert(data);
    }cout<<"enter value to deleted";
    int val;cin>>val;
    deleted(val);
    print(head);
}
