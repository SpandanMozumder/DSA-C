#include <stdio.h>
#include <stdlib.h>

// Define an AVL tree node
struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
    int height; // Height of the node
};

// Function to calculate the height of a node
int height(struct TreeNode *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->height;
}

// Function to calculate the maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Function to create a new node
struct TreeNode *createNode(int value)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1; // New node is at height 1
    return newNode;
}

// Function to perform a right rotation (RR) on a subtree rooted with y
struct TreeNode *rightRotate(struct TreeNode *y)
{
    struct TreeNode *x = y->left;
    struct TreeNode *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// Function to perform a left rotation (LL) on a subtree rooted with x
struct TreeNode *leftRotate(struct TreeNode *x)
{
    struct TreeNode *y = x->right;
    struct TreeNode *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Function to get the balance factor of a node
int getBalance(struct TreeNode *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return height(node->left) - height(node->right);
}

// Function to insert a value into an AVL tree
struct TreeNode *insert(struct TreeNode *root, int value)
{
    // Perform standard BST insertion
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
    else
    {
        // Duplicate values are not allowed in AVL tree
        return root;
    }

    // Update height of current node
    root->height = 1 + max(height(root->left), height(root->right));

    // Get the balance factor to check if the node is unbalanced
    int balance = getBalance(root);

    // Left Left Case (LL)
    if (balance > 1 && value < root->left->data)
    {
        return rightRotate(root);
    }

    // Right Right Case (RR)
    if (balance < -1 && value > root->right->data)
    {
        return leftRotate(root);
    }

    // Left Right Case (LR)
    if (balance > 1 && value > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case (RL)
    if (balance < -1 && value < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function to print the inorder traversal of the AVL tree
void inorderTraversal(struct TreeNode *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to free the memory of the AVL tree
void freeTree(struct TreeNode *root)
{
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main()
{
    struct TreeNode *root = NULL;

    // Insert values to create an unbalanced tree
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 10);
    root = insert(root, 25);
    root = insert(root, 5);

    printf("Inorder Traversal of AVL tree: ");
    inorderTraversal(root);
    printf("\n");

    // Clean up: Free allocated memory
    freeTree(root);

    return 0;
}
