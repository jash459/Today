// Link : https://www.naukri.com/code360/problems/delete-middle-node_763267?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

// video :https://www.youtube.com/watch?v=ePpV-_pfOeI

/*
1. Brute
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
// Write your code here.
if (head == null || head->next == null) return null;
int count = 0;
Node temp = head;
while( temp != null){
count++;
temp = temp->next;
}
Node current = head;
int res = count/2;
while(current != null){
res--;
if(res == 0){
Node* middle= current->next;
current->next = current->next->next;
free(middle);
break;
}
current = current->next;
}
return head;
}
}
T.C: O(N + N/2)
S.C: O(1)*/

// 2. Optimal

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        // here we want to skip 1 step, as we want to reach 1st middle, as we dont want to reach the middle, we want to reach one step before middle, so that we can connect the middle prev to middle next, and in case of even length, we will delete 2nd middle
        fast = fast -> next -> next;
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        Node* middle = slow->next;
        free(middlle);
        slow -> next = slow -> next -> next;
        return head;
    }
};