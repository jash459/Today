// Link : https://takeuforward.org/data-structure/search-in-a-binary-search-tree-2/

// video : https://www.youtube.com/watch?v=KcNt6v_56cc&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=40

#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

node* searchBST(node* root, int target) {
    while(root != NULL && root->data != target){
        root = target<root->data? root->left:root->right;
    }
    return root;
}

int main() {

  struct node * root = newNode(8);
  root -> left = newNode(5);
  root -> left -> left = newNode(4);
  root -> left -> right = newNode(7);
  root -> left -> right -> left = newNode(6);
  root -> right = newNode(12);
  root -> right -> left = newNode(10);
  root -> right -> right = newNode(14);
  root -> right -> right ->left = newNode(13);

  node* found = searchBST(root,10);
  
  if(found != NULL)
    cout<<"Node value with given target found";
  else cout<<"Node value with given target not found";

  return 0;
}
// Output:
// Node value with given target found
// Time Complexity: O(logN)
// Reason: The time required will be proportional to the height of the tree, if the tree is balanced, then the height of the tree is logN.
// Space Complexity: O(1)
// Reason: We are not using any extra space.

/*
Intuition: 
We are given a binary search tree. In a binary search tree, for every node the following property is satisfied:

Values in the left subtree < Value of node < Values in the right subtree 

Therefore, whenever we are at a node, if its value is equal to the value we are searching for,(say target),  we have found our answer and we can return the node address. Else, we can compare the target value to the node’s value. If the target value is less than it we will find our answer in the left subtree else we will find it in the right subtree. At every step, we decrease our search space by half, which is nothing else than binary search.

Approach:
The algorithm steps can be stated as:

Set a while loop which runs till the time root is not NULL and root’s value is not equal to the target value we are searching for.
Inside the while loop, if the target value is less than the root’s value, move root to its left child, else move root to its right child.
When the while loop ends, return root as the answer.

*/