// Link : https://takeuforward.org/data-structure/boundary-traversal-of-a-binary-tree/

// video : https://www.youtube.com/watch?v=0ca1nvR0be4&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=20

#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

bool isLeaf(node * root) {
  return !root -> left && !root -> right;
}

void addLeftBoundary(node * root, vector < int > & res) {
  node * cur = root -> left;
  while (cur) {
    if (!isLeaf(cur)) res.push_back(cur -> data);
    if (cur -> left) cur = cur -> left;
    else cur = cur -> right;
  }
}
void addRightBoundary(node * root, vector < int > & res) {
  node * cur = root -> right;
  vector < int > tmp;
  while (cur) {
    if (!isLeaf(cur)) tmp.push_back(cur -> data);
    if (cur -> right) cur = cur -> right;
    else cur = cur -> left;
  }
  for (int i = tmp.size() - 1; i >= 0; --i) {
    res.push_back(tmp[i]);
  }
}

void addLeaves(node * root, vector < int > & res) {
  if (isLeaf(root)) {
    res.push_back(root -> data);
    return;
  }
  if (root -> left) addLeaves(root -> left, res);
  if (root -> right) addLeaves(root -> right, res);
}

vector < int > printBoundary(node * root) {
  vector < int > res;
  if (!root) return res;

  if (!isLeaf(root)) res.push_back(root -> data);

  addLeftBoundary(root, res);

  // add leaf nodes
  addLeaves(root, res);

  addRightBoundary(root, res);
  return res;
}

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

int main() {

  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> left -> left = newNode(3);
  root -> left -> left -> right = newNode(4);
  root -> left -> left -> right -> left = newNode(5);
  root -> left -> left -> right -> right = newNode(6);
  root -> right = newNode(7);
  root -> right -> right = newNode(8);
  root -> right -> right -> left = newNode(9);
  root -> right -> right -> left -> left = newNode(10);
  root -> right -> right -> left -> right = newNode(11);

  vector < int > boundaryTraversal;
  boundaryTraversal = printBoundary(root);

  cout << "The Boundary Traversal is : ";
  for (int i = 0; i < boundaryTraversal.size(); i++) {
    cout << boundaryTraversal[i] << " ";
  }
  return 0;
}
// Output:

// The Boundary Traversal is : 1 2 3 4 5 6 10 11 9 8 7 

// Time Complexity: O(N).

// Reason: The time complexity will be O(H) + O(H) + O(N) which is ≈ O(N)

// Space Complexity: O(N)

// Reason: Space is needed for the recursion stack while adding leaves. In the worst case (skewed tree), space complexity can be O(N).

/*

Approach: Boundary traversal in an anti-clockwise direction can be described as a traversal consisting of three parts:

Part 1: Left Boundary of the tree (excluding the leaf nodes).
Part 2: All the leaf nodes travelled in the left to right direction.
Part 3: Right Boundary of the tree (excluding the leaf nodes), traversed in the reverse direction.
We take a simple data structure like a vector/Arraylist to store the Boundary Traversal. The root node is coming from both the boundaries (left and right). Therefore, to avoid any confusion, we push it on our list at the very start.*/