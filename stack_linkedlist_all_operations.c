#include <stdio.h>
#include <stdlib.h>

// Node structure for a stack
struct Node
{
    int data;
    struct Node *next;
};

// Stack structure
struct Stack
{
    struct Node *top;
};

// Function to initialize an empty stack
void initStack(struct Stack *stack)
{
    stack->top = NULL;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack)
{
    return (stack->top == NULL);
}

// Function to push an element onto the stack
void push(struct Stack *stack, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("Pushed %d onto the stack\n", data);
}

// Function to pop an element from the stack
int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        fprintf(stderr, "Stack is empty. Cannot pop.\n");
        exit(EXIT_FAILURE);
    }
    struct Node *temp = stack->top;
    int poppedValue = temp->data;
    stack->top = temp->next;
    free(temp);
    printf("Popped %d from the stack\n", poppedValue);
    return poppedValue;
}

// Function to peek at the top element of the stack
int peek(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        fprintf(stderr, "Stack is empty. Cannot peek.\n");
        exit(EXIT_FAILURE);
    }
    return stack->top->data;
}

// Function to display the elements of the stack
void displayStack(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty.\n");
        return;
    }
    struct Node *current = stack->top;
    printf("Stack: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free the memory allocated for the stack
void freeStack(struct Stack *stack)
{
    while (stack->top != NULL)
    {
        struct Node *temp = stack->top;
        stack->top = temp->next;
        free(temp);
    }
}

int main()
{
    struct Stack myStack;
    initStack(&myStack);

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    displayStack(&myStack);

    printf("Top element: %d\n", peek(&myStack));

    pop(&myStack);

    displayStack(&myStack);

    freeStack(&myStack);

    return 0;
}
