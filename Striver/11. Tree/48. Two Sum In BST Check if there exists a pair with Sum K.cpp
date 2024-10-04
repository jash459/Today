// Link : https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

// video : https://www.youtube.com/watch?v=ssL3sHwPeb4&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=51

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& inorderVal) {
        if (root == NULL) {
            return;
        }
        inorder(root->left, inorderVal);
        inorderVal.push_back(root->val);
        inorder(root->right, inorderVal);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorderVal;
        inorder(root, inorderVal);

        int i = 0;
        int j = inorderVal.size() - 1;
        while (i < j) {
            int sum = inorderVal[i] + inorderVal[j];
            if (sum == k) {
                return true;
            } else if (sum < k) {
                i++;
            } else {
                j--;
            }
        }

        return false;
    }
};