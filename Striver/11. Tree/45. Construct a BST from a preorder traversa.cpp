// Link : https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/

// video : https://www.youtube.com/watch?v=UmJT3j26t1I&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=48

class Solution {
public:
    TreeNode* solve(vector<int>& preorder , int mini , int maxi , int &i){
        //base cases
        if(i >= preorder.size())
            return NULL;
        
        if(preorder[i] < mini || preorder[i] > maxi)
            return NULL;
        
        TreeNode* temp = new TreeNode(preorder[i++]);
        temp->left = solve(preorder , mini , temp->val , i);
        temp->right = solve(preorder , temp->val , maxi , i);
        
        return temp;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return solve(preorder , INT_MIN , INT_MAX , i);
    }
};