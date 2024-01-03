#include <stdio.h>
#include <stdlib.h>

// Node structure for a binary tree
struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Stack structure for non-recursive traversal
struct StackNode
{
    struct TreeNode *node;
    struct StackNode *next;
};

// Function to push a node onto the stack
void push(struct StackNode **stack, struct TreeNode *node)
{
    struct StackNode *newNode = (struct StackNode *)malloc(sizeof(struct StackNode));
    if (newNode == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->node = node;
    newNode->next = *stack;
    *stack = newNode;
}

// Function to pop a node from the stack
struct TreeNode *pop(struct StackNode **stack)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    struct TreeNode *poppedNode = (*stack)->node;
    struct StackNode *temp = *stack;
    *stack = (*stack)->next;
    free(temp);
    return poppedNode;
}

// Function to check if the stack is empty
int isStackEmpty(struct StackNode *stack)
{
    return stack == NULL;
}

// Function to create a new node
struct TreeNode *createNode(int data)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
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

// Function to create a binary tree
struct TreeNode *createBinaryTree()
{
    struct TreeNode *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    return root;
}

// Function for non-recursive inorder traversal
void inorderTraversal(struct TreeNode *root)
{
    struct TreeNode *current = root;
    struct StackNode *stack = NULL;

    while (current != NULL || !isStackEmpty(stack))
    {
        while (current != NULL)
        {
            push(&stack, current);
            current = current->left;
        }

        current = pop(&stack);
        printf("%d ", current->data);

        current = current->right;
    }
}

// Function for non-recursive preorder traversal
void preorderTraversal(struct TreeNode *root)
{
    if (root == NULL)
        return;

    struct TreeNode *current = root;
    struct StackNode *stack = NULL;

    push(&stack, current);

    while (!isStackEmpty(stack))
    {
        current = pop(&stack);
        printf("%d ", current->data);

        if (current->right != NULL)
            push(&stack, current->right);
        if (current->left != NULL)
            push(&stack, current->left);
    }
}

// Function for non-recursive postorder traversal
void postorderTraversal(struct TreeNode *root)
{
    if (root == NULL)
        return;

    struct TreeNode *current = root;
    struct StackNode *stack1 = NULL;
    struct StackNode *stack2 = NULL;

    push(&stack1, current);

    while (!isStackEmpty(stack1))
    {
        current = pop(&stack1);
        push(&stack2, current);

        if (current->left != NULL)
            push(&stack1, current->left);
        if (current->right != NULL)
            push(&stack1, current->right);
    }

    while (!isStackEmpty(stack2))
    {
        current = pop(&stack2);
        printf("%d ", current->data);
    }
}

int main()
{
    struct TreeNode *root = createBinaryTree();

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
