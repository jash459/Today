//Link : https://www.naukri.com/code360/problems/find-pairs-with-given-sum-in-doubly-linked-list_1164172?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

//video : https://www.youtube.com/watch?v=YitR4dQsddE

/*
1. Brute
vector<pair<int, int>> findPairs(Node* head, int k)
{
    vector<pair<int, int>>vp;
    Node* temp = head;
    unordered_map<int, int>mp;
    while(temp != nullptr)
    {
        int x = k-(temp -> data);
        if(mp.find(x) != mp.end())
        {
            vp.push_back({x, temp->data});
        }
        else{
            mp[temp->data]++;
        }
        temp = temp -> next;
    }
    return vp;
}
O(N), SC O(N)*/


// Optimal

#include<bits/stdc++.h>
using namespace std;

//Node class
class Node {
public:
     int data;
     Node *prev;
     Node *next;
     Node() {
         this->data = 0;
         this->prev = NULL;
         this->next = NULL;
     }
     Node(int data) {
         this->data = data;
         this->prev = NULL;
         this->next = NULL;
     }
     Node (int data, Node *next, Node *prev) {
         this -> data = data;
         this -> prev = prev;
         this -> next = next;
     }
};


Node* findTail(Node* head) {
    Node* tail = head;
    while (tail->next != NULL)
        tail = tail->next;
    return tail;
}

vector<pair<int, int>> findPairs(Node* head, int k) {
    vector<pair<int, int>> ans;
    if (head == NULL)
        return ans; 

    Node* left = head;
    Node* right = findTail(head); //O(N)

    while (left->data < right->data) {
        if (left->data + right->data == k) {
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        } else if (left->data + right->data < k) {
            left = left->next;
        } else {
            right = right->prev;
        }
    }

    return ans;
}

// T.C:  O(2N), S.C: O(1);