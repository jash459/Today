// Link : https://takeuforward.org/binary-search-tree/ceil-in-a-binary-search-tree/

// video : https://www.youtube.com/watch?v=KSsk8AhdOZA&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=41

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

int findCeil(node *root, int input)
{

    int ceil = -1;
    
    while (root)
    {
        // If the input is already available in BST, return that.
        if (root->data == input)
            return input;

        // If the input is greater than root, then the ceil value must be in the right subtree.
        else if (root->data < input)
        {
            root = root->right;
        }

        // Otherwise, we mark ceil to be root and move to 
        // left subtree where it may be further closer to the input value
        else
        {
            ceil = root->data;
            root = root->left;
        }
    }

    //Return computed ceil value.
    return ceil;
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

    cout << findCeil(root, 6);
    cout << endl;

    return 0;
}
// Output: 7
// Time Complexity: O(log(N)) {Similar to Binary Search, at a given time we’re searching one half of the tree, so the time taken would be of the order log(N) where N are the total nodes in the BST and log(N) is the height of the tree.}
// Space Complexity: O(1) {As no extra space is being used, we’re just traversing the BST.}

/*
Approach:
This Problem can be easily solved by using a similar approach as we use to Binary Search a linear array and find the number that is just greater or equal to the given target input value.

Algorithm:
We start from the root element and check whether the number whose ceil we have to find out is equal to the value of the root or not. If its value is equal, we simply return the number.
Now, if the value of the number is not equal to the root’s value but is greater, we can conclude by saying that the number’s ceil value also lies in the right subtree of the given BST because, in BST, the right subtree contains all the elements whose values are greater than the root element.
If the value of the number, however, is lesser than the root’s value, then a possible ceil value could be the root itself as the number is less than its value. So, to check whether the number can be reduced further, we move to the left subtree and keep on updating the ceiling value accordingly.
Once, we encounter any node whose value is null, we return the computed ceil value.

*/
