Node* merge(Node* head){
      if(head==NULL || head->next==NULL){
          return head;
      }
      Node* slow=head,*fast=head;
      Node* temp=NULL;
      while(fast && fast->next){
          temp=slow;
          slow=slow->next;
          fast=fast->next->next;
      }
      temp->next=NULL;
      Node* t1=merge(head);
      Node* t2=merge(slow);
      return sortedMerge(t1,t2);
      
      
  }
    Node* sortedMerge(Node* head1, Node* head2) {
        // code here
        Node* dummy=new Node(0);
        Node* current=dummy;
        while(head1 && head2){
            if(head1->data<=head2->data){
                current->next=head1;
                head1=head1->next;
            }else{
                current->next=head2;
                head2=head2->next;
            }
            current=current->next;
        }
        if(head1)current->next=head1;
        if(head2)current->next=head2;
        return dummy->next;
        
    }
