// Link : https://www.geeksforgeeks.org/sum-of-two-linked-lists/
//      : https://takeuforward.org/data-structure/add-two-numbers-represented-as-linked-lists/

// video : https://www.youtube.com/watch?v=XmRrGzR6udg
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1); 
        ListNode *current = dummy;
        ListNode *temp1 = l1; 
        ListNode *temp2 = l2; 
        int carry = 0;
        while( (temp1 != NULL || temp2 != NULL)) {
            int sum = carry; 
            if(temp1) {
                sum += temp1->val; 
            }     
            if(temp2 != NULL) {
                sum += temp2 -> val; 
            }
            ListNode *newNode = new ListNode(sum % 10); 
            carry = sum / 10; 
            current->next= newNode;
            current= current->next;
            if(temp1) temp1= temp1->next;
            if(temp2) temp2= temp2->next;
        }
        if(carry){
            ListNode* newNode = new ListNode(carry);
            current-> next = newNode;
        }
        return dummy -> next; 
    }
};
// Time Complexity: O(max(m,n)). Assume that m and n represent the length of l1 and l2 respectively, the algorithm above iterates at most max(m,n) times.

// Space Complexity: O(max(m,n)). The length of the new list is at most max(m,n)+1.