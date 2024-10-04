// Link : https://www.naukri.com/code360/problems/sort-linked-list-of-0s-1s-2s_1071937?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

//video : https://www.youtube.com/watch?v=gRII7LhdJWc

/*
1. Brute
#include <bits/stdc++.h>
/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

Node* sortList(Node *head){
    int zerocount = 0,onecount =0,twocount = 0;
    Node* temp  = head;
    while(temp){
        if(temp->data == 0){  zerocount++;}
        else if(temp->data == 1){  onecount++;}
        else{  twocount++;}
        temp = temp->next;
    }
    temp = head;
    while(temp){
        for(int i = 1 ; i <= zerocount ; i++){
            temp->data = 0;
            temp = temp->next;
        }
        for(int i = 1 ; i <= onecount ; i++){
            temp->data = 1;
            temp = temp->next;
        }
        for(int i = 1 ; i <= twocount ; i++){
            temp->data = 2;
            temp = temp->next;
        }
    }
    return head;
}
T.C: O(2N)
S.C: O(1)
*/

// 2.Optimal 

class Node

{
public:
int data;
Node *next;
Node()
{
this->data = 0;
next = NULL;
}
Node(int data)
{
this->data = data;
this->next = NULL;
}
Node(int data, Node* next)
{
this->data = data;
this->next = next;
}
};

Node* sortList(Node *head){
// Write your code here.
if(head == NULL || head->next == NULL) return head;
Node* zeroHead = new Node(-1);
Node* oneHead = new Node(-1);
Node* twoHead = new Node(-1);
Node* zero = zeroHead;
Node* one = oneHead;
Node* two = twoHead;
Node* temp = head;
while(temp){
if(temp->data==0)
{
zero->next = temp;
zero = zero->next;
else if (temp->data == 1)
{
one->next = temp;
one = one->next;
}
else {
two->next = temp;
two = two->next;
}
temp = temp->next;
}
zero->next = (oneHead->next) ? (oneHead->next) : twoHead->next;
one->next = twoHead->next;
two->next = NULL;
Node* newHead = zeroHead->next;
delete zeroHead;
delete oneHead;
delete twoHead;
return newHead;
}
}
// T.C: O(N)
// S.C: O(1)