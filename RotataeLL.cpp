Node* rotate(Node* head, int k) {
         if (k == 0 || head == nullptr)
        return head;
        int cnt=1;
        Node* temp=head;
        while(temp->next){
            temp=temp->next;cnt++;
        }
        k=k%cnt;
        if(k==0) return head;
        temp->next=head;
        temp=head;
       for(int i=1;i<k;i++){
           temp=temp->next;
           
       }
       head=temp->next;
       temp->next=nullptr;
       return head;
    }
