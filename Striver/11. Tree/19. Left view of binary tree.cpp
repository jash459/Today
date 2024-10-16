// Link : https://takeuforward.org/data-structure/right-left-view-of-binary-tree/

// video : https://www.youtube.com/watch?v=KV4mRzTjlAk&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=24

Code: For the right view of the binary tree.


Explain
class Solution {
public:
    void recursion(TreeNode *root, int level, vector<int> &res)
    {
        if(root==NULL) return ;
        if(res.size()==level) res.push_back(root->val);
        recursion(root->right, level+1, res);
        recursion(root->left, level+1, res);
    }
    
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        recursion(root, 0, res);
        return res;
    }
};
// Time Complexity: O(N)

// Space Complexity: O(H)       (H -> Height of the Tree)

// Code: For the left view of binary tree.


Explain
class Solution {
public:
    void recursion(TreeNode *root, int level, vector<int> &res)
    {
        if(root==NULL) return ;
        if(res.size()==level) res.push_back(root->val);
        recursion(root->left, level+1, res);
        recursion(root->right, level+1, res);
    }
    
    vector<int> leftSideView(TreeNode *root) {
        vector<int> res;
        recursion(root, 0, res);
        return res;
    }
};
// Time Complexity: O(N)

// Space Complexity: O(H)       (H -> Height of the Tree)

/*
Intuition: We have to do a Recursive Level Order Traversal.

Root Right Left     —-> for Right view

Root Left Right     —–> for Left view

Approach: 

Create an vector data structure inside both the left and the right side view function
Call for the recursive _left and recursive_right function respectively with the (root,level,vector). Here level will be initially passed as 0.
Return the vector.
Now in the recursive_left function
If vector size is equal to the level then push_back its node value to the vector data structure.
Otherwise call recursive_left for (node->left,level+1,vector)
Call recursive_left for (node->right,level+1,vector)
Now in the recursive_right function
If vector size is equal to the level then push_back its node value to the vector data structure.
Otherwise call recursive_right for (node->right,level+1,vector)
Call recursive_right for (node->left,level+1,vector)
Tip: The Code for the Left and the Right View is almost identical. 

In the Right view code first, you have to call the recursive function for the right then the left node

AND

In the Right view code first, you have to call the recursive function for the Left than the right node
*/