Node* flatten(Node* head) {
         Node* curr = head;

        while (curr) {
            if (curr->child) {
                Node* child = curr->child;

                // Find the tail of the child list
                while (child->next) {
                    child = child->next;
                }

                // Connect child's tail to curr's next node (if it exists)
                child->next = curr->next;
                if (curr->next) {
                    curr->next->prev = child;
                }

                // Connect curr to child
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = nullptr; // Remove child pointer
            }

            curr = curr->next;
        }

        return head;
    }
