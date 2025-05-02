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
void removed(Node* head){
    unordered_set<int>s;
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
        if(s.find(temp->data)!=s.end()){
            prev->next=temp->next;
            delete temp;
            temp=prev->next;
        }else{
            s.insert(temp->data);
            prev=temp;
            temp=temp->next;
        }
    }
   
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
   removed(head);
   print(head);
  
   

    return 0;
}
