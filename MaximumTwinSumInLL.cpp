 ListNode* reverse(ListNode* head){
       ListNode* curr=head,*prev=nullptr,*next=nullptr;
       while(curr){
         next=curr->next;
         curr->next=prev;
         prev=curr;
         curr=next;
       }
       return prev;
    }
    
    int pairSum(ListNode* head) {
        ListNode* slow=head,*fast=head;
        while(fast&& fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* second=reverse(slow);
        slow->next=nullptr;
        ListNode* first = head;
        int maxSum = 0;
        while (second) {
            maxSum = max(maxSum, first->val + second->val);
            first = first->next;
            second = second->next;
        }

        return maxSum;
    }
