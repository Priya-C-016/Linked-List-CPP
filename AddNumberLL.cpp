Node* reverse(Node* head){
        Node* curr=head,*prev=nullptr,*next=nullptr;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    Node* removeLeadingZeros(Node* head){
        while(head  && head->data==0  && head->next){
            head=head->next;
        }
        return head;
    }
    Node* addTwoLists(Node* t1, Node* t2) {
        // code here
        t1=reverse(t1);
        t2=reverse(t2);
        Node* dummy=new Node(0);
        Node* current=dummy;
        int carry=0;
        while(t1 || t2|| carry){
            int val1=t1?t1->data:0;
            int val2=t2? t2->data:0;
            int sum=val1+val2+carry;
            carry=sum/10;
            current->next= new Node(sum%10);
            current=current->next;
            if(t1)t1=t1->next;
            if(t2)t2=t2->next;
        }
        Node* result=reverse(dummy->next);
        result = removeLeadingZeros(result);
        return result;
        
    }
