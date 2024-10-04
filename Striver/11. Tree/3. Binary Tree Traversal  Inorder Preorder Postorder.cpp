// Link : https://takeuforward.org/binary-tree/binary-tree-traversal-inorder-preorder-postorder/

// video : https://www.youtube.com/watch?v=jmy0LaGET1I&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=4

// 1. Inorder :

struct node {
  int data;
  struct node * left, * right;
};

void inOrderTrav(node * curr, vector < int > & inOrder) {
  if (curr == NULL)
    return;

  inOrderTrav(curr -> left, inOrder);
  inOrder.push_back(curr -> data);
  inOrderTrav(curr -> right, inOrder);
}

// 2. Preorder :

struct node {
  int data;
  struct node * left, * right;
};

void preOrderTrav(node * curr, vector < int > & preOrder) {
  if (curr == NULL)
    return;

  preOrder.push_back(curr -> data);
  preOrderTrav(curr -> left, preOrder);
  preOrderTrav(curr -> right, preOrder);
}

//3. Postorder :

struct node {
  int data;
  struct node * left, * right;
};

void postOrderTrav(node * curr, vector < int > & postOrder) {
  if (curr == NULL)
    return;

  postOrderTrav(curr -> left, postOrder);
  postOrderTrav(curr -> right, postOrder);
  postOrder.push_back(curr -> data);
}

// 4. LevelOrder :

vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans; 

        if(root == NULL) return ans; 

        queue<TreeNode*> q; 
        q.push(root); 

        while(!q.empty()) {
            int size = q.size();
            vector<int> level; 
            for(int i = 0;i<size;i++) {
                TreeNode *node = q.front(); 
                q.pop(); 
                if(node->left != NULL) q.push(node->left); 
                if(node->right != NULL) q.push(node->right); 
                level.push_back(node->val); 
            }

            ans.push_back(level); 
        }

        return ans; 
    }