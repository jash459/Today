// Link : https://takeuforward.org/binary-tree/count-number-of-nodes-in-a-binary-tree/

// video : https://www.youtube.com/watch?v=u-yWemKGWO0&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=33

/*
1. Brute 

Solution 1: Using any tree traversal – O(N) Approach

Approach:

The first approach that comes to our mind is to use any tree traversal ( say inorder), and count the number of nodes as we are traversing the tree.


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

void inOrderTrav(node * curr, int& count) {
  if (curr == NULL)
    return;

  count++;
  inOrderTrav(curr -> left, count);
  inOrderTrav(curr -> right, count);
}

int main() {

  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> right = newNode(3);
  root -> left -> left = newNode(4);
  root -> left -> right = newNode(5);
  root -> right -> left = newNode(6);

  int count = 0;
  inOrderTrav(root, count);

  cout << "The total number of nodes in the given complete binary tree are: "
  <<count;
  return 0;
}
Output:
The total number of nodes in the given complete binary tree are: 6
Time Complexity: O(N).
Reason: We are traversing for every node of the tree
Space Complexity: O(logN)
Reason: Space is needed for the recursion stack. As it is a complete tree, the height of that stack will always be logN.*/

// 2. Optimal Approach 2: Efficient Approach – O(log^2 N) solution

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

void inOrderTrav(node * curr, int& count) {
  if (curr == NULL)
    return;

  count++;
  inOrderTrav(curr -> left, count);
  inOrderTrav(curr -> right, count);
}
 
    int findHeightLeft(node* cur) {
        int hght = 0; 
        while(cur) {
            hght++; 
            cur = cur->left; 
        }
        return hght; 
    }
    int findHeightRight(node* cur) {
        int hght = 0; 
        while(cur) {
            hght++; 
            cur = cur->right; 
        }
        return hght; 
    }
    int countNodes(node* root) {
        if(root == NULL) return 0; 
        
        int lh = findHeightLeft(root); 
        int rh = findHeightRight(root); 
        
        if(lh == rh) return (1<<lh) - 1; 
        
        int leftNodes = countNodes(root->left);
        int rightNodes = countNodes(root->right);
        
        return 1 + leftNodes + rightNodes; 
    }

int main() {

  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> right = newNode(3);
  root -> left -> left = newNode(4);
  root -> left -> right = newNode(5);
  root -> right -> left = newNode(6);
  root -> right -> right = newNode(7);
  root -> left -> left -> left = newNode(8);
  root -> left -> left -> right = newNode(9);
  root -> left -> right -> left = newNode(10);
  root -> left -> right -> right = newNode(11);


  cout << "The total number of nodes in the given complete binary tree are: "
  <<countNodes(root);
  return 0;
}
// Output:
// The total number of nodes in the given complete binary tree are: 11
// Time Complexity: O(log^2 N).
// Reason: To find the leftHeight and right Height we need only logN time and in the worst case we will encounter the second case(leftHeight!=rightHeight) for at max logN times, so total time complexity will be O(log N * logN)
// Space Complexity: O(logN)
// Reason: Space is needed for the recursion stack when calculating height. As it is a complete tree, the height will always be logN.

/*
Approach:

The algorithm steps can be stated as :

Set a recursive function to calculate the number of nodes.
In the recursive function, calculate leftHeight and the right Height of the tree from the given node.
If leftHeight == rightHeight, return 2leftHeight – 1.
If leftHeight != rightHeight, recursively call the function to calculate nodes in left subtree(leftNodes) and the right subtree(rightNodes) and return 1+leftNodes+rightNodes.

*/
/*
What is a complete binary tree?
A complete binary tree is a biary tree whose:
All levels except the last one are completely filled. The last level may or may not be completely filled.
Nodes in the last level are as left as possible.

*/