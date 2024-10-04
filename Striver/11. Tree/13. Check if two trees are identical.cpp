// Link : https://takeuforward.org/data-structure/check-if-two-trees-are-identical/

// video : https://takeuforward.org/data-structure/check-if-two-trees-are-identical/

#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

bool isIdentical(node * node1, node * node2) {
  if (node1 == NULL && node2 == NULL)
    return true;
  else if (node1 == NULL || node2 == NULL)
    return false;

  return ((node1 -> data == node2 -> data) && isIdentical(node1 -> left, node2 -> left) && isIdentical(node1 -> right, node2 -> right));
}

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

int main() {

  struct node * root1 = newNode(1);
  root1 -> left = newNode(2);
  root1 -> right = newNode(3);
  root1 -> right -> left = newNode(4);
  root1 -> right -> right = newNode(5);

  struct node * root2 = newNode(1);
  root2 -> left = newNode(2);
  root2 -> right = newNode(3);
  root2 -> right -> left = newNode(4);

  if (isIdentical(root1, root2))
    cout << "Two Trees are identical";
  else cout << "Two trees are non-identical";

  return 0;
}
// Output:

// Two trees are non-identical

// Time Complexity: O(N).

// Reason: We are doing a tree traversal.

// Space Complexity: O(N)

// Reason: Space is needed for the recursion stack. In the worst case (skewed tree), space complexity can be O(N).

/*

Approach: In order to check whether two trees are identical or not, we need to traverse the trees. While traversing we first check the value of the nodes, if they are unequal we can simply return false, as trees are non-identical. If they are the same, then we need to recursively check their left child as well as the right child. When we get all the three values as true(node values, left child, right child) we can conclude that these are identical trees and can return true. Any other combination will return false.*/