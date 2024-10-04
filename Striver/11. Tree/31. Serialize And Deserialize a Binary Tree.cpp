// Link : https://www.geeksforgeeks.org/serialize-deserialize-binary-tree/
//      : https://takeuforward.org/data-structure/serialize-and-deserialize-a-binary-tree/

// video : https://www.youtube.com/watch?v=-YbXySKJsX8

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        
        string s ="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
           TreeNode* curNode = q.front();
           q.pop();
           if(curNode==NULL) s.append("#,");
           else s.append(to_string(curNode->val)+',');
           if(curNode != NULL){
               q.push(curNode->left);
               q.push(curNode->right);            
           }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL; 
        stringstream s(data);
        string str; 
        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode*> q; 
        q.push(root); 
        while(!q.empty()) {
            
            TreeNode *node = q.front(); 
            q.pop(); 
            
            getline(s, str, ',');
            if(str == "#") {
                node->left = NULL; 
            }
            else {
                TreeNode* leftNode = new TreeNode(stoi(str)); 
                node->left = leftNode; 
                q.push(leftNode); 
            }
            
            getline(s, str, ',');
            if(str == "#") {
                node->right = NULL; 
            }
            else {
                TreeNode* rightNode = new TreeNode(stoi(str)); 
                node->right = rightNode;
                q.push(rightNode); 
            }
        }
        return root; 
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)

/*

The time complexity for both the `serialize` and `deserialize` functions in this code is O(N), where N is the number of nodes in the binary tree.

Let's analyze both functions separately:

1. `serialize`:
   - The function uses a level-order traversal (BFS) to visit each node once.
   - For each node, constant time operations are performed (appending the value to the string).
   - Therefore, the overall time complexity is O(N).

2. `deserialize`:
   - The function uses a level-order traversal (BFS) to visit each node once.
   - For each node, constant time operations are performed (creating new nodes and setting their values).
   - Therefore, the overall time complexity is O(N).

In summary, the time complexity for both `serialize` and `deserialize` is O(N), where N is the number of nodes in the binary tree.

*/

/*

Worst Case explain 

In the worst-case scenario, the characteristics of the binary tree can lead to the maximum number of nodes being visited and stored. Let's consider the worst-case scenarios for both serialization and deserialization:

1. **Worst Case for Serialization:**
    - Suppose we have a completely unbalanced binary tree, where each node only has a left child. In this case, the queue will be filled with all the nodes in the leftmost branch before moving to the right branch.
    - The queue will store all nodes in the left branch before moving on to the right branch, and this pattern continues until the last level of the tree.
    - In this situation, all nodes will be visited, and the serialization process will iterate through each node once.
    - This results in a worst-case time complexity of O(N) and a worst-case space complexity of O(N), where N is the number of nodes in the binary tree.

2. **Worst Case for Deserialization:**
    - Similar to the serialization worst case, if the binary tree is completely unbalanced with all nodes having only left children, the deserialization process will create nodes in the leftmost branch first.
    - The queue will be filled with all nodes in the left branch before moving on to the right branch, and this pattern continues until the last level of the tree.
    - In this case, all nodes will be processed during deserialization, resulting in a worst-case time complexity of O(N).
    - The queue will store all nodes in the left branch before moving on to the right branch, resulting in a worst-case space complexity of O(N).

So, the worst-case scenario for both serialization and deserialization occurs when the binary tree is completely unbalanced, leading to a linear time and space complexity.*/

/*

Why BFS :

The choice to use Breadth-First Search (BFS) in the serialization and deserialization of the binary tree is mainly for simplicity and ease of implementation. BFS is a natural fit for this scenario for the following reasons:

1. **Level-order Traversal:** BFS naturally traverses the tree level by level. In the `serialize` function, this helps in ensuring that the nodes are processed in the order they appear in the tree, making it easy to reconstruct the tree during deserialization.

2. **Sequential Representation:** When serializing the tree, BFS ensures that the values of nodes at each level are appended to the string in the order they appear from left to right. This sequential representation allows for a straightforward deserialization process.

3. **Queue-based Processing:** BFS can be easily implemented using a queue. Nodes are processed in the order they are dequeued, ensuring that child nodes are processed only after their parent has been processed. This queue-based approach simplifies the logic for both serialization and deserialization.

While BFS is a good choice for simplicity, it's worth noting that other traversal algorithms like Depth-First Search (DFS) could also be used. However, DFS might require additional information to be included in the serialized string to reconstruct the tree properly, such as marking null nodes or specifying whether a node is a left or right child.

In summary, BFS is chosen for its natural fit in processing nodes level by level, making it simpler to serialize and deserialize the binary tree.*/