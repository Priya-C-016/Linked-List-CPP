Node* segregate(Node* head) {
        // code here
        vector<int>ans(3,0);
        Node* temp=head;
        while(temp){
            ans[temp->data]++;
            temp=temp->next;
        }
        Node*h1=head;
        while(h1){
            for(int i=0;i<3;i++){
                while(ans[i]--){
                    h1->data=i;
                    h1=h1->next;
                }
            }
        }
        return head;
    }
