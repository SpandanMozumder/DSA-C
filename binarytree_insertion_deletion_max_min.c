#include <stdio.h>
#include <stdlib.h>

// Node structure for the binary search tree
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the binary search tree
struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to find the minimum value in the binary search tree
struct Node *findMin(struct Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

// Function to find the maximum value in the binary search tree
struct Node *findMax(struct Node *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

// Function to delete a value from the binary search tree
struct Node *deleteNode(struct Node *root, int data)
{
    if (root == NULL)
    {
        return root;
    }

    // Traverse the tree to find the node to be deleted
    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        // Node with only one child or no child
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct Node *temp = findMin(root->right);

        // Copy the inorder successor's data to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Function to perform inorder traversal
void inorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main()
{
    struct Node *root = NULL;

    // Insert values into the binary search tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    // Find minimum and maximum values
    struct Node *minValueNode = findMin(root);
    struct Node *maxValueNode = findMax(root);

    printf("Minimum value in the BST: %d\n", minValueNode->data);
    printf("Maximum value in the BST: %d\n", maxValueNode->data);

    // Delete a value from the binary search tree
    int valueToDelete = 30;
    root = deleteNode(root, valueToDelete);

    printf("Inorder Traversal after deletion of %d: ", valueToDelete);
    inorderTraversal(root);
    printf("\n");

    return 0;
}
