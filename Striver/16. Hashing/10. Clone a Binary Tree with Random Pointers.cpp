// Link : https://www.geeksforgeeks.org/clone-binary-tree-random-pointers/

// video : https://www.youtube.com/watch?v=lPAeiLyXwfY
class Solution{
  public:
    // Step-1: constructing tree using left and right pointer
    Node* getCopiedTree(Node* root, unordered_map<Node*,Node*> &mp){
        if(!root) return NULL;
        mp[root] = new Node(root->data);
        mp[root]->left = getCopiedTree(root->left,mp);
        mp[root]->right = getCopiedTree(root->right,mp);
        return mp[root];
    }
    
    // Step-2: using preorder traversal connect random pointer
    void connectRandom(Node* root, unordered_map<Node*,Node*> &mp){
        if(!root) return;
        mp[root]->random = mp[root->random];
        connectRandom(root->left,mp);
        connectRandom(root->right,mp);
    }
    
    Node* cloneTree(Node* tree){
        unordered_map<Node*,Node*> mp;
        Node* root = getCopiedTree(tree,mp);
        connectRandom(tree,mp);
        // step-3: return root of new clone tree
        return root;
    }
};

/*
Time Complexity:

The total time complexity is the sum of the complexities of getCopiedTree and connectRandom.
Both methods individually have O(n) time complexity.
Thus, the total time complexity is O(n).
Space Complexity:

The total space complexity is the sum of the space used by the hash map and the recursion stack.
The hash map uses O(n) space, and the recursion stack uses O(n) space in the worst case.
Thus, the total space complexity is O(n).
Summary:
Time Complexity: O(n)
Space Complexity: O(n)
*/