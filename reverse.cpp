#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
};
void insert(Node* &head,int data){
    Node * newNode=new Node();
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
    temp=head;
}
void reverse(Node* &head){
    Node* curr=head,*temp=NULL,*prev=NULL;
    while(curr!=NULL){
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    head=prev;
}
void print(Node* head){
    Node * temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
    int n;
    cout<<"enter the number";
    cin>>n;
    Node* head=NULL;
    while(n--){
        int data;
        cin>>data;
        insert(head,data);
    }
    print(head);
    reverse(head);
    print(head);
}
