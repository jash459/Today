// Link : https://www.naukri.com/code360/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list_8160461?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

// video : https://www.youtube.com/watch?v=Mh0NH_SD92k

// Optimal 

Node * deleteAllOccurrences(Node* head, int k) {
    // Write your code here
    if(head == NULL) return head;
    Node *temp = head;
    while(temp) {
        if(temp->data == k) {
            if(temp == head) {
                head = head->next;
            }
            Node *prevNode = temp->prev;
            Node *nextNode = temp->next;
            if(prevNode) prevNode->next = nextNode;
            if(nextNode) nextNode->prev = prevNode;
            free(temp);
            temp = nextNode;
        }
    else temp = temp->next;       
    }
    return head;
}

// TC:- O(n) SC:- O(1)


// in case of LL
Node * deleteAllOccurrences(Node* head, int k) {
    // Write your code here
    if(head == NULL) return head;
    if(head->next == NULL) {
        if(k == head->data) {
            delete(head);
            return NULL;
        }
        return head;
    }
    Node *temp = head;
    while(temp && k == temp->data) {
        Node *delNode = temp;
        temp = temp->next;
        free(delNode); 
    }
    if(temp == NULL) return NULL;
    Node *newHead = temp;
    while(temp->next) {
        if(k == temp->next->data) {
            Node *delNode = temp->next;
            temp->next = delNode->next;
            free(delNode);
        }
    else temp = temp->next;       
    }
    return newHead;
}

/*
Time Complexity (TC): The time complexity of this code snippet is O(n), where n is the number of nodes in the list. This is because it traverses the list once from left to right, deleting or skipping nodes as needed.

Space Complexity (SC): The space complexity of this code snippet is O(1), as it does not use any extra memory apart from the input parameters and local variables. It only uses a constant amount of space.*/