// Link : https://www.codingninjas.com/studio/problems/predecessor-and-successor-in-bst_893049?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

// video : https://www.youtube.com/watch?v=SXKAD2svfmI&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=49

// coding ninjas solution
pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    int pred = -1;
    int succ = -1;
    TreeNode* temp = root;
    while(temp && temp->data != key){  
        if(temp->data > key){
            succ = temp->data;
            temp = temp->left;
        }
        else{
            pred = temp->data;
            temp = temp->right;
        }
    }
    if(temp){
        // predecessor
        TreeNode* leftTree = temp->left;
        while(leftTree){
            pred = leftTree->data;
            leftTree = leftTree->right;
        }
        // successor
        TreeNode* rightTree = temp->right;
        while(rightTree){
            succ = rightTree->data;
            rightTree = rightTree->left;
        }
    }
    return {pred, succ};
}


// striver video :

Inorder Successor in BST of given Node
class Solution {
public:
    TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {

        TreeNode* successor = NULL;
        while(root!=NULL){
            if(p->val >= root->val){
                root = root->right;
            }
            else{
                successor = root;
                root = root->left;
            }
        }
        return successor;
    }
};

Inorder predecessor in BST of given Node
class Solution {
public:
    TreeNode * inorderPredecessor(TreeNode * root, TreeNode * p) {

        TreeNode* predecessor = NULL;
        while(root!=NULL){
            if(root->val >= p->val){
                root = root->left;
            }
            else{
                predecessor = root;
                root = root->right;
            }
        }
        return predecessor;
    }
};