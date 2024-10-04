// Link : https://www.naukri.com/code360/problems/add-one-to-a-number-represented-as-linked-list_920557?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

// video : https://www.youtube.com/watch?v=aXQWhbvT3w0

/*
1. Brute
Node reverse(Node head){
    if(head == NULL || head->next ==NULL){
        return head; 
    }
    Node *newhead = reverse(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newhead;
}


Node *addOne(Node *head)
{
   // naive solution 
   
    head = reverse(head);
    Node* temp = head;
    int carry = 1;
    while(temp!=NULL){
        temp->data = temp->data+carry;
        if(temp->data<10){
            carry =0;
            break;
        }else{
            temp->data =0;
            carry =1;
        }

        temp= temp->next;
    }
    if(carry ==1){
        Node* newNode= new Node(1);
        head = reverse(head);
        newNode->next = head;
        return newNode;
    }

    head = reverse(head);
    return head;
}
T.C.: O(3N)
S.C: O(1)
*/

// 2. Optimal 
int helper(Node* temp){
    if(temp == NULL){
        return 1;
    }
    int carry = helper(temp->next);
    temp->data+= carry;
    if(temp->data <10) return 0;
        temp->data=0;
        return 1;
}
Node *addOne(Node *head)
{
    int carry = helper(head);
    if(carry ==1){
        Node* newNode= new Node(1);
        newNode->next = head;
        return newNode;
    }
    return head;
}

// T.C.: O(N)
// S.C: O(N)