// Link : https://takeuforward.org/data-structure/construct-binary-tree-from-inorder-and-postorder-traversal/

// video : https://www.youtube.com/watch?v=LgLRTaEMRVc&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=36

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
node * constructTree(vector < int > & postorder, int postStart, int postEnd, 
vector < int > & inorder, int inStart, int inEnd, map < int, int > & mp) {
  if (postStart > postEnd || inStart > inEnd) return NULL;

  node * root = newNode(postorder[postEnd]);
  int elem = mp[root -> data];
  int nElem = elem - inStart;

  root -> left = constructTree(postorder, postStart, postStart + nElem - 1, 
  inorder, inStart, elem - 1, mp);
  root -> right = constructTree(postorder, postStart + nElem, postEnd-1, inorder,
  elem + 1, inEnd, mp);

  return root;
}

node * buildTree(vector < int > & postorder, vector < int > & inorder) {
  int postStart = 0, postEnd = postorder.size() - 1;
  int inStart = 0, inEnd = inorder.size() - 1;

  map < int, int > mp;
  for (int i = inStart; i <= inEnd; i++) {
    mp[inorder[i]] = i;
  }

  return constructTree(postorder, postStart, postEnd, inorder, inStart, inEnd, mp);
}

int main() {

  vector<int> postorder{40,50,20,60,30,10};
  vector<int> inorder{40,20,50,10,60,30};
  node * root = buildTree(postorder, inorder);
  return 0;
}
// Time Complexity: O(N)
// Assumption: Hashmap returns the answer in constant time.
// Space Complexity: O(N)
// Reason: We are using an external hashmap of size ‘N’.

/*
Intuition:

Inorder traversal is a special traversal that helps us to identify a node and its left and right subtree. Postorder traversal always gives us the root node as its last element. Using these properties we can construct the unique binary tree.

Approach:

The algorithm approach can be stated as:

Create a map to store the inorder indexes.
Call the function constructTree with all 7 parameters as shown above.
In the recursive function, first check the base case, if (postStart,>postEnd || inStart> inEnd) then return NULL.
Construct a node (say root) with the root value( last element of postorder). 
Find the index of the root, say elem from the hashmap.
Find the number of elements ( say nElem) in the left subtree  = elem – inStart
 Call recursively for the left subtree with correct values (shown in the above table) and store the answer received in root->left.
Call recursively for the right subtree with correct values (shown in the above table) and store the answer received in root->right.
Return root
*/