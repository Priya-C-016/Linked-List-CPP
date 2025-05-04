ListNode* reverseKGroup(ListNode* head, int k) {
      if(head==NULL && k==1)return head;
      ListNode*dummy=new ListNode(0);
      dummy->next=head;
      ListNode*prev=dummy;
      int cnt=0;
      ListNode* curr=head;
      while(curr){
        cnt++;
        curr=curr->next;
      }
      while(cnt>=k){
        curr=prev->next;
        ListNode*next=curr->next;
        for(int i=1;i<k;i++){
            curr->next=next->next;
            next->next=prev->next;
            prev->next=next;
            next=curr->next;
        }
        prev=curr;
        cnt-=k;
      }
      return dummy->next;
    }
