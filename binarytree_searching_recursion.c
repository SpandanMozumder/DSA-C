#include <stdio.h>
#include <stdlib.h>

// Node structure for the binary tree
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

// Function to search for a value in a binary tree
struct Node *searchInTree(struct Node *root, int key)
{
    // Base Cases: root is null or key is present at the root
    if (root == NULL || root->data == key)
    {
        return root;
    }

    // Key is greater than root's key
    if (key > root->data)
    {
        return searchInTree(root->right, key);
    }

    // Key is smaller than root's key
    return searchInTree(root->left, key);
}

// Function to insert a new node with the given key
struct Node *insertNode(struct Node *root, int key)
{
    // Base case: if the tree is empty, return a new node
    if (root == NULL)
    {
        return createNode(key);
    }

    // Otherwise, recur down the tree
    if (key < root->data)
    {
        root->left = insertNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = insertNode(root->right, key);
    }

    // return the unchanged node pointer
    return root;
}

// Function to perform inorder traversal of the tree
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
    // Create a binary tree
    struct Node *root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    // Search for a value in the tree
    int keyToSearch = 40;
    struct Node *searchResult = searchInTree(root, keyToSearch);

    if (searchResult != NULL)
    {
        printf("Element %d found in the tree\n", keyToSearch);
    }
    else
    {
        printf("Element %d not found in the tree\n", keyToSearch);
    }

    return 0;
}
