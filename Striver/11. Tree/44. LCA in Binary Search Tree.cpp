// Link : https://takeuforward.org/binary-search-tree/lca-in-binary-search-tree/

// video : https://www.youtube.com/watch?v=cX_kPV_foZc&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=47

#include <iostream>
#include <climits>
using namespace std;

// Definition of TreeNode structure
// for a binary tree node
struct TreeNode {
    // Value of the node
    int val;
    
    // Pointer to the left child node
    TreeNode* left;
    
    // Pointer to the right child node
    TreeNode* right;

    // Constructor to initialize the node with a
    // value and set left and right pointers to null
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to find the lowest common ancestor (LCA)
    // of two nodes in a binary search tree (BST)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Check if the root is null
        if (root == nullptr) {
            // If null, return null as there's no LCA
            return nullptr; 
        }
        
        // Store the value of the current root node
        int curr = root->val;
        
        // If both p and q values are greater
        // than the current root's value
        if (curr < p->val && curr < q->val) {
            // Recursively search in the
            // right subtree for the LCA
            return lowestCommonAncestor(root->right, p, q);
        }
        
        // If both p and q values are smaller
        // than the current root's value
        if (curr > p->val && curr > q->val) {
            // Recursively search in the
            // left subtree for the LCA
            return lowestCommonAncestor(root->left, p, q);
        }
        
        // If the values are on either side of the current root's value,
        // or one of the values matches the current root's value,
        // return the current root as the LCA
        return root;
    }
};


// Function to perform an in-order traversal
// of a binary tree and print its nodes
void printInOrder(TreeNode* root) {
    // Check if the current node
    // is null (base case for recursion)
    if (root == nullptr) {
        // If null, return and
        // terminate the function
        return;
    }

    // Recursively call printInOrder
    // for the left subtree
    printInOrder(root->left);

    // Print the value of the current node
    cout << root->val << " ";

    // Recursively call printInOrder
    // for the right subtree
    printInOrder(root->right);
}

int main() {
    Solution solution;

    // Creating a sample tree
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    cout << "Inorder Traversal of Tree:" << endl;
    printInOrder(root);
    cout << endl;

    // Node with value 2
    TreeNode* p = root->left->left;  
    
    // Node with value 4
    TreeNode* q = root->left->right; 
    
    TreeNode* lca = solution.lowestCommonAncestor(root, p, q);

    cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is: " << lca->val << endl;

    return 0;
}
// Output:
// Inorder Traversal of Tree:
// 2 3 4 6 7 8
// Lowest Common Ancestor of 2 and 4 is: 3
// Time Complexity: O(H) where H is the height of the binary search tree as we are traversing along the height of the tree. In comparison to LCA in a binary tree where the time complexity is O(N), finding LCA in a binary search tree is more optimised.
// Space Complexity: O(1) as no additional data structure or memory allocation is done during the traversal and algorithm.

/*
Approach: 
In a Binary Search Tree (BST), finding the Lowest Common Ancestor (LCA) involves traversing the tree from the root while comparing the values of the two nodes with the current node. At each step, if both nodes are smaller, move left; if larger, move right. When they diverge (one left, one right, or one is the current node), that node is the LCA.

This approach leverages the BST’s structure, efficiently narrowing down the search space based on node values.

Algorithm:
Step 1: Start at the root of the Binary Search Tree.

Step 2: Compare the values of the two nodes with the value of the current node.

If both nodes are smaller than the current node, they are both to its left hence move to its left child.
If both nodes are larger than the current node, they are both to its right hence move to its right child.
If one node is to the left and the other to the right of the current node, or if one node is the current node itself, then the current node is the LCA.
Step 3: Traverse down the tree based on the comparison of the node values, narrow done the search space by eliminating subtrees where the LCA cannot exist.


Step 4: Stop the recursion when both nodes are found in different subtrees of the current node or one of the nodes become the current node itself. Return the current node.
*/