// Link : https://leetcode.com/problems/binary-search-tree-iterator/solutions/3384349/c-solution/

// video : https://www.youtube.com/watch?v=D2jMcmxU4bs&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=50

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> stk;
    void pushAll(TreeNode* root){
        while (root){
            stk.push(root);
            root= root->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* node= stk.top();
        stk.pop();
        pushAll(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return (!stk.empty());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */