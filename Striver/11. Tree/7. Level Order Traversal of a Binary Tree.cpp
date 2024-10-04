// Link : https://takeuforward.org/data-structure/level-order-traversal-of-a-binary-tree/

// video : https://www.youtube.com/watch?v=EoAsWbO7sqg&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=8

class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> ans; 
        
        if(root == NULL) 
            return ans; 
            
        queue<TreeNode*> q; 
        q.push(root); 
        
        while(!q.empty()) {
           
            TreeNode *temp = q.front(); 
            q.pop(); 
            
            if(temp->left != NULL) 
                q.push(temp->left); 
            if(temp->right != NULL) 
                q.push(temp->right); 
                
            ans.push_back(temp->val); 
        }
        return ans; 
    }
};
Time Complexity: O(N)

Space Complexity: O(N)