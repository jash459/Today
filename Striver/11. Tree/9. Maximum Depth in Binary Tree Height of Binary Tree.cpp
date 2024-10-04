// Link : https://takeuforward.org/data-structure/maximum-depth-of-a-binary-tree/

// video : https://www.youtube.com/watch?v=eD3tmO66aBA&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=14

// Recursively ( Post Order Traversal )
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0; 
        
        int lh = maxDepth(root->left); 
        int rh = maxDepth(root->right); 
        
        return 1 + max(lh, rh); 
    }
};
// Time Complexity: O(N) 

// Space Complexity: O(1) Extra Space + O(H) Recursion Stack space, where “H”  is the height of the binary tree.