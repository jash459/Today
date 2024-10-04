// Link : https://takeuforward.org/binary-search-tree/floor-in-a-binary-search-tree/

// video : https://www.youtube.com/watch?v=xm_W1ub-K-w&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=42

#include <bits/stdc++.h>

using namespace std;

//Declaring the struct for Tree implementation.
struct node
{
    int data;
    struct node *left, *right;
};

//Defining a function for inserting new-node in BST
struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

int findFloor(node *root, int input)
{

    int floor = -1;
    
    while (root)
    {
        // If the input is already available in BST, return that.
        if (root->data == input)
            return input;

        // If the input is greater than root, we mark floor to be root and move to 
        // right subtree where it may be further closer to the input value
        else if (root->data < input)
        {
            floor = root->data;
            root = root->right;
        }

        // Otherwise, the floor value must be in the left subtree.
        else
        {
            root = root->left;
        }
    }

    //Return computed floor value.
    return floor;
}

int main()
{
    // Driver Code.
    struct node *root = newNode(10);
    root->left = newNode(5);
    root->left->left = newNode(4);
    root->left->right = newNode(7);
    root->left->right->right = newNode(8);
    root->right = newNode(11);

    cout << findFloor(root, 6);
    cout << endl;

    return 0;
}
// Output: 5
// Time Complexity: O(log(N)) {Similar to Binary Search, at a given time we’re searching one half of the tree, so the time taken would be of the order log(N) where N are the total nodes in the BST and log(N) is the height of the tree.}
// Space Complexity: O(1) {As no extra space is being used, we’re just traversing the BST.}

/*
Approach:
This Problem can be easily solved by using a similar approach as we use to Binary Search a linear array and find the number which is just lesser or equal to the given target input value.

Algorithm:
We start from the root element and check whether the number whose floor we have to find out is equal to the value of the root or not. If its value is equal, we simply return the number.
Now, if the value of the number is not equal to the root’s value but is lesser, we can conclude by saying that the number’s floor value also lies in the left subtree of the given BST because, in BST, the left subtree contains all the elements whose values are lesser than the root element.
If the value of the number, however, is greater than the root’s value, then a possible floor value could be the root itself as the number is less than its value. So, to check whether the number can be increased further, we move to the right subtree and keep on updating the floor value accordingly.
Once, we encounter any node whose value is null, we return the computed floor value.

*/