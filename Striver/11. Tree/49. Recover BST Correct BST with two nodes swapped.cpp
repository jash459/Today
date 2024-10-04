// Link : https://leetcode.com/problems/recover-binary-search-tree/description/

// video : https://www.youtube.com/watch?v=ZWGW7FminDM&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=52\

/*
Time complexity:O(N)+O(logn)=O(logn)
Space complexity:O(N)
1. Brute 
  Definition for a binary tree node.
  struct TreeNode {
      int val;
     TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:

   void fn(TreeNode* root,vector<int>&ans)
   {
      if(root==NULL)
      return;
      fn(root->left,ans);
      ans.push_back(root->val);
      fn(root->right,ans);

   }
   int i=0;
   void check(TreeNode* root,vector<int>&ans)
   {
       if(root==NULL)
       {
           return;
       }
       check(root->left,ans);            ///LEFT   SWAP   RIGHT
       if(root->val!=ans[i])
       {
           swap(root->val,ans[i]); ///THIS IS HOW WE CHECK WHEATHER FIRST ELEMNT OF INORDER IS SAME AS OF THE SORTED ARRAY
       }
       i++;
       check(root->right,ans);
   }
    void recoverTree(TreeNode* root) {
        vector<int>ans;
        fn(root,ans);
        sort(ans.begin(),ans.end());
        check(root,ans);
        
        
    }
};
*/
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
class Solution {
private:
  TreeNode* first;
  TreeNode* prev;
  TreeNode* middle;
  TreeNode* last;
private:
  void inorder(TreeNode *root)
  {
      if(root==NULL)return;
      inorder(root->left);
      if(prev!=NULL && root->val<prev->val)
      {
          if(first==NULL)
          {
              first=prev;
              middle=root;
          }
          else
          {
              last=root;
          }
      }
      prev=root;
      inorder(root->right);
  }
       
public:
    void recoverTree(TreeNode* root) {
        first=middle=last=NULL;
        prev= new TreeNode(INT_MIN);
        inorder(root);
        if(first && last)
        {
            swap(first->val,last->val);
        }
        else
        {
            swap(first->val,middle->val);
        }
    }
};

// OPTIMAL SOLUTION
// THERE CAN BE 2 CASES-
// 1)SWAPPED NODES ARE ADJACENT.
// 2)SWAPPED NODES ARE NOT ADJACENT
// Time complexity:O(N) ONLY INORDER TRAVERSAL
// Space complexity:O(1) MORRIS TRAVERSAL