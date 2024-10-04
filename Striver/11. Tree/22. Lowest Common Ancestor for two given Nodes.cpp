// Link : https://takeuforward.org/data-structure/lowest-common-ancestor-for-two-given-nodes/

// video : https://www.youtube.com/watch?v=_-QHfMDde90&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=28

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if (root == NULL || root == p || root == q) {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        //result
        if(left == NULL) {
            return right;
        }
        else if(right == NULL) {
            return left;
        }
        else { //both left and right are not null, we found our result
            return root;
        }
    }
};
// Time complexity: O(N) where n is the number of nodes.
// Space complexity: O(N), auxiliary space.

/*

Intuition:

The very first thing we can observe from the question is that we can find the LCA of 2 given nodes from 

        i) Left subtree or in

       ii)Right subtree, if not in both the subtrees then root will be the  LCA.

Approach:

If root is null or if root is x or if root is y then return root
Made a recursion call for both
i) Left subtree 

ii)Right subtree

Because we would find LCA in the left or right subtree only.

If the left subtree recursive call gives a null value that means we haven’t found LCA in the left subtree, which means we found LCA on the right subtree. So we will return right.
If the right subtree recursive call gives null value, that means we haven’t found LCA on the right subtree, which means we found LCA on the left subtree. So we will return left .
If both left & right calls give values (not null)  that means the root is the LCA.

*/