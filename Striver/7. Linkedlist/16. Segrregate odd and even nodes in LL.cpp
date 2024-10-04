// Link : https://www.naukri.com/code360/problems/segregate-even-and-odd-nodes-in-a-linked-list_1116100?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

// video : https://www.youtube.com/watch?v=qf6qp7GzD5Q

/*
1. Brute 

#include<bits/stdc++.h>

Node* oddEvenList(Node* head)
{
    if(head == nullptr && head->next == nullptr){
        return head;
    }
    vector<int> arr;  
    Node* temp = head;
    while(temp != nullptr && temp->next != nullptr){
        arr.push_back(temp->data);
       temp = temp->next->next;
    }
    if(temp){
        arr.push_back(temp->data);
    }
    temp = head->next;  // temp pointer updated, now its in second node, not doing the same step 2 times 
    while (temp != nullptr && temp->next != nullptr) {
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    if(temp){
        arr.push_back(temp->data);
    }
    int i=0;
    temp = head;
    while(temp != nullptr){
        temp->data = arr[i];
        i++;
        temp = temp->next;
    }
    return head;
}
*/

// 2. Optimal

Node* oddEvenList(Node* head)
{
	if(head==NULL || head->next==NULL) return head;
    Node * odd = head;
    Node * even = head->next;
    Node * evenhead = even;
    while(even && even->next){
        odd->next=odd->next->next;
        even->next=even->next->next;
        odd=odd->next;
        even=even->next;
    }
    odd->next = evenhead;
    return head;
}

// T.C: O(n), S.C: O(1)