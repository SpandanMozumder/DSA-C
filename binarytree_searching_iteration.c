#include <stdio.h>
#include <stdlib.h>

// Define a binary search tree node
struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode *createNode(int value)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the binary search tree
struct TreeNode *insert(struct TreeNode *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to perform iterative search in a binary search tree
struct TreeNode *iterativeSearch(struct TreeNode *root, int target)
{
    while (root != NULL)
    {
        if (target == root->data)
        {
            return root; // Found the target value
        }
        else if (target < root->data)
        {
            root = root->left; // Move left
        }
        else
        {
            root = root->right; // Move right
        }
    }

    return NULL; // Target value not found
}

int main()
{
    struct TreeNode *root = NULL;

    // Insert some values into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Search for a value in the BST iteratively
    int target = 60;
    struct TreeNode *result = iterativeSearch(root, target);

    if (result != NULL)
    {
        printf("Value %d found in the binary search tree.\n", target);
    }
    else
    {
        printf("Value %d not found in the binary search tree.\n", target);
    }

    // Clean up: Free allocated memory (not shown in detail for simplicity)
    return 0;
}
