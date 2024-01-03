#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Stack structure
struct Stack
{
    int arr[MAX_SIZE];
    int top;
};

// Function to initialize the stack
void initializeStack(struct Stack *stack)
{
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack *stack)
{
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, int data)
{
    if (isFull(stack))
    {
        printf("Stack overflow. Cannot push element %d\n", data);
        return;
    }
    stack->arr[++stack->top] = data;
    printf("Pushed %d onto the stack\n", data);
}

// Function to pop an element from the stack
int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow. Cannot pop from an empty stack\n");
        exit(EXIT_FAILURE);
    }
    int poppedElement = stack->arr[stack->top--];
    printf("Popped %d from the stack\n", poppedElement);
    return poppedElement;
}

// Function to peek at the top element of the stack without removing it
int peek(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty. Cannot peek\n");
        exit(EXIT_FAILURE);
    }
    return stack->arr[stack->top];
}

int main()
{
    struct Stack myStack;
    initializeStack(&myStack);

    // Push elements onto the stack
    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    // Peek at the top element
    printf("Top element of the stack: %d\n", peek(&myStack));

    // Pop elements from the stack
    int poppedElement1 = pop(&myStack);
    int poppedElement2 = pop(&myStack);

    // Display popped elements
    printf("Popped elements: %d, %d\n", poppedElement1, poppedElement2);

    // Peek after popping
    printf("Top element of the stack after popping: %d\n", peek(&myStack));

    return 0;
}
