//Link : https://www.naukri.com/code360/problems/remove-duplicates-from-a-sorted-doubly-linked-list_2420283?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

// video: https://www.youtube.com/watch?v=YJKVTnOJXSY

Node * removeDuplicates(Node *head){

    if(head==nullptr || head->next==nullptr) return head;
    Node* temp=head;

    while(temp->next){
        if(temp->data == temp->next->data){
            Node* curr=temp->next;
            temp->next=curr->next;
            if(curr->next) curr->next->prev=temp;
            free(curr);
        }
        else{temp=temp->next;}
    }
    return head;
}

// T.C. :O(N), S.C: O(1)

// Striver

Node* removeDuplicates(Node *head){
    /* Pointer to traverse the linked list */
    Node* current = head;

    /* Pointer to store the next pointer of a node to be
     * deleted*/
    Node* next_next;

    /* do nothing if the list is empty */
    if (current == NULL)
        return;

    /* Traverse the list till last node */
    while (current->next != NULL) {
        /* Compare current node with next node */
        if (current->data == current->next->data) {
            /* The sequence of steps is important*/
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        }
        else /* This is tricky: only advance if no deletion
              */
        {
            current = current->next;
        }
    }
    return head;
}