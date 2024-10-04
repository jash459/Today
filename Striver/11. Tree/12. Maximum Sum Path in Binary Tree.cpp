// Link : https://takeuforward.org/data-structure/maximum-sum-path-in-binary-tree/

// video : https://www.youtube.com/watch?v=WszrfSwMz58&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=17

#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

int findMaxPathSum(node * root, int & maxi) {
  if (root == NULL) return 0;

  int leftMaxPath = max(0, findMaxPathSum(root -> left, maxi));
  int rightMaxPath = max(0, findMaxPathSum(root -> right, maxi));
  int val = root -> data;
  maxi = max(maxi, (leftMaxPath + rightMaxPath) + val);
  return max(leftMaxPath, rightMaxPath) + val;

}

int maxPathSum(node * root) {
  int maxi = INT_MIN;
  findMaxPathSum(root, maxi);
  return maxi;

}

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

int main() {

  struct node * root = newNode(-10);
  root -> left = newNode(9);
  root -> right = newNode(20);
  root -> right -> left = newNode(15);
  root -> right -> right = newNode(7);

  int answer = maxPathSum(root);
  cout << "The Max Path Sum for this tree is " << answer;

  return 0;
}
// The Max Path Sum for this tree is 42

// Time Complexity: O(N).

// Reason: We are doing a tree traversal.

// Space Complexity: O(N)

// Reason: Space is needed for the recursion stack. In the worst case (skewed tree), space complexity can be O(N).

/*

Initialize a maxi variable to store our final answer.
Do a simple tree traversal. At each node, find  recursively its leftMaxPath and its rightMaxPath.
Calculate the maxPath through the node as val + (leftMaxPath + rightMaxPath) and update maxi accordingly.
Return the maxPath when node is not the curving point as val + max(leftMaxPath, rightMaxPath).*/