// Link : https://www.geeksforgeeks.org/find-the-minimum-element-in-a-binary-search-tree/

/*
// C++ program to find minimum value node in binary search
// Tree.
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child 
struct node {
	int data;
	struct node* left;
	struct node* right;
};

/* Helper function that allocates a new node
with the given data and NULL left and right
pointers. 
struct node* newNode(int data)
{
	struct node* node
		= (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/* Give a binary search tree and a number,
inserts a new node with the given number in
the correct place in the tree. Returns the new
root pointer which the caller should then use
(the standard trick to avoid using reference
parameters). 
struct node* insert(struct node* node, int data)
{
	/* 1. If the tree is empty, return a new,
		single node 
	if (node == NULL)
		return (newNode(data));
	else {
		/* 2. Otherwise, recur down the tree 
		if (data <= node->data)
			node->left = insert(node->left, data);
		else
			node->right = insert(node->right, data);

		/* return the (unchanged) node pointer 
		return node;
	}
}

/* Given a non-empty binary search tree,
return the minimum data value found in that
tree. Note that the entire tree does not need
to be searched. 
int minValue(struct node* node)
{
	struct node* current = node;

	/* loop down to find the leftmost leaf 
	while (current->left != NULL) {
		current = current->left;
	}
	return (current->data);
}

/* Driver Code
int main()
{
	struct node* root = NULL;
	root = insert(root, 4);
	insert(root, 2);
	insert(root, 1);
	insert(root, 3);
	insert(root, 6);
	insert(root, 5);

	// Function call
	cout << "\n Minimum value in BST is " << minValue(root);
	getchar();
	return 0;
}

// This code is contributed by Mukul Singh.
Time Complexity: O(n) where n is the number of nodes.
Auxiliary Space: O(1)
*/

// 2. Another approach Modified binary search approach:

// CPP program to implement the modified binary search approach
#include <iostream>
using namespace std;

// Node class for BST
class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int data) {
		this->data = data;
		left = right = nullptr;
	}
};

// Function to find the minimum element in a BST
int findMinimum(Node* root) {
	if (root == nullptr) {
		return -1;
	}
	while (root->left != nullptr) { // Traverse to the leftmost node
		if (root->left->data < root->data) {
			root = root->left;
		} else {
			root = root->right;
		}
	}
	return root->data;
}

// Driver code
int main() {
	// Create a BST
	Node* root = new Node(4);
	root->left = new Node(2);
	root->right = new Node(6);
	root->left->left = new Node(1);
	root->left->right = new Node(3);
	root->right->left = new Node(5);
	root->right->right = new Node(7);

	// Find the minimum element in the BST
	int minVal = findMinimum(root);

	// Print the minimum element
	cout << "Minimum element in the BST is: " << minVal << endl;

	return 0;
}

// This code is contributed by Susobhan Akhuli

// Time Complexity: O(log n) , This approach has a time complexity of O(log n), where n is the number of nodes in the BST.
// space complexity: O(1).