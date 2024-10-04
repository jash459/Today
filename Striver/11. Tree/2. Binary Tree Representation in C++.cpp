// Link : https://takeuforward.org/binary-tree/binary-tree-representation-in-c/

// video : https://www.youtube.com/watch?v=ctCpP0RFDFc&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=2

Struct Node{

// Defining value of the node.
int data;

// Left reference ptr to the node.
Struct Node* left;

// Right reference ptr to the node.
Struct Node* right;

// Method to initialize the above values.
Node (int val)
{
  data = val;
  left = right = NULL; 
}

};

main()
{
   // Creating a new node by using dynamic allocation.
   Struct Node* root = new Node(1);
   root -> left = new Node(2);
   root -> right = new Node(3);
   root -> left -> right = new Node(5);

}