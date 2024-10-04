// Link : https://www.naukri.com/code360/problems/sort-linked-list_625193?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

// video : https://www.youtube.com/watch?v=8ocB7a_c-Cc

/*
1. Brute

ListNode* sortList(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;
        
        // Extract values from the linked list and store them in the vector
        while(temp != nullptr){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        
        // Sort the vector
        sort(arr.begin(), arr.end());
        
        // Update the linked list with sorted values
        temp = head;
        for(int i = 0; temp != nullptr; i++){
            temp->val = arr[i];
            temp = temp->next;
        }     
        return head; 
T.C. : O(N + NlogN + N)
S.C : O(N)
}
*/

// 2. Optimal :

ListNode* findMiddleNode(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next; // head->next because we want slow to point to the first element/middle in the even length case

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // merge linked list function
    ListNode* merge(ListNode* list1Head, ListNode* list2Head) {
        ListNode* dummyNode = new ListNode(-1); // can be any value
        ListNode* temp = dummyNode;

        while (list1Head != NULL && list2Head != NULL) {
            if (list1Head->val <= list2Head->val) {
                temp->next = list1Head;
                temp = list1Head;
                list1Head = list1Head->next;
            } else {
                temp->next = list2Head;
                temp = list2Head;
                list2Head = list2Head->next;
            }
        }

        // if list1 still has elements left
        while (list1Head != NULL) {
            temp->next = list1Head;
            temp = list1Head;
            list1Head = list1Head->next;
        }

        // if list2 still has elements left
        while (list2Head != NULL) {
            temp->next = list2Head;
            temp = list2Head;
            list2Head = list2Head->next;
        }
        return dummyNode->next;
    }

    // MergeSort recursive
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* mid = findMiddleNode(head);
        ListNode* leftHead = head;
        ListNode* rightHead = mid->next;
        mid->next = NULL; // Disconnect the left and right halves

        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);
        return merge(leftHead, rightHead);
    }
T.C. : O(logN * (N + N/2))
S.C : O(1)