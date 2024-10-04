// Link : https://takeuforward.org/data-structure/find-middle-element-in-a-linked-list/

// video : https://www.youtube.com/watch?v=7LjQ57RqgEc

/*
1. Brute 
class Solution {
public:
	ListNode* middleNode(ListNode* head) {
    	int n = 0;
    	ListNode* temp = head;
    	while(temp) {
        	n++;
        		temp = temp->next;
    	}
   	 
    	temp = head;
   	 
    	for(int i = 0; i < n / 2; i++) {
        		temp = temp->next;
    	}
   	 
    	return temp;
	}
};
*/

// 2. Optimal : Tortoise-Hare-Approach

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
		// fast->next odd, in this fast reach last node, fast -> even, in case of even length in this fast reach NULL, we will return 2nd middle
            slow = slow->next, fast = fast->next->next;
        return slow;
    }
};
// Time Complexity: O(N)

// Space Complexity: O(1)

