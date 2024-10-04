// Link : https://takeuforward.org/data-structure/calculate-the-diameter-of-a-binary-tree/

// video : https://www.youtube.com/watch?v=Rezetez59Nk&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=16

// Post prder traversal
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }

private:
    int height(TreeNode* node, int& diameter) {

        if (!node) {
            return 0;
        }

        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);

        diameter = max(diameter, lh + rh);

        return 1 + max(lh, rh);
    }
};
// Time Complexity: O(N) 

// Space Complexity: O(1) Extra Space + O(H) Recursion Stack space (Where “H”  is the height of binary tree )  

/*
Post Order Traversal

Intuition :

Is it possible to optimize the above solution further? Which operation do you think is very repetitive in nature in the above solution?

💡 Height of the subtrees.

Can we use postorder traversal to calculate everything in a single traversal of the tree?

Yes, as in post-order traversal, we have to completely traverse the left and right subtree before visiting the root node.

So, the idea is to use post-order traversal and keep calculating the height of the left and right subtrees. Once we have the heights at the current node, we can easily calculate both the diameter and height of the current node.

Approach : 

Start traversing the tree recursively and do work in Post Order.
In the Post Order of every node , calculate diameter and height of the current node.
If current diameter is maximum then update the variable used to store the maximum diameter.
Return height of current node to the previous recursive call.
*/