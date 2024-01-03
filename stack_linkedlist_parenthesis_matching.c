#include <stdio.h>
#include <stdlib.h>

// Node structure for the stack
struct Node
{
    char data;
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

// Function to push a character onto the stack
void push(struct Stack *stack, char data)
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
}

// Function to pop a character from the stack
char pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        fprintf(stderr, "Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    struct Node *temp = stack->top;
    char poppedValue = temp->data;
    stack->top = temp->next;
    free(temp);
    return poppedValue;
}

// Function to perform parenthesis matching
int isParenthesisMatching(const char *expression)
{
    struct Stack myStack;
    initStack(&myStack);

    for (int i = 0; expression[i] != '\0'; i++)
    {
        char currentChar = expression[i];

        if (currentChar == '(' || currentChar == '[' || currentChar == '{')
        {
            push(&myStack, currentChar);
        }
        else if (currentChar == ')' || currentChar == ']' || currentChar == '}')
        {
            if (isEmpty(&myStack))
            {
                return 0; // Unbalanced - no opening bracket to match with
            }

            char topChar = pop(&myStack);

            // Check if the popped opening bracket matches the current closing bracket
            if ((topChar == '(' && currentChar != ')') ||
                (topChar == '[' && currentChar != ']') ||
                (topChar == '{' && currentChar != '}'))
            {
                return 0; // Unbalanced - mismatched brackets
            }
        }
    }

    // Check if there are any unmatched opening brackets left in the stack
    return isEmpty(&myStack);
}

int main()
{
    const char *expression1 = "{(a + b) * (c - d)}";
    const char *expression2 = "[(a + b) * (c - d)]";
    const char *expression3 = "{(a + b) * (c - d)";

    if (isParenthesisMatching(expression1))
    {
        printf("Expression 1 is balanced\n");
    }
    else
    {
        printf("Expression 1 is not balanced\n");
    }

    if (isParenthesisMatching(expression2))
    {
        printf("Expression 2 is balanced\n");
    }
    else
    {
        printf("Expression 2 is not balanced\n");
    }

    if (isParenthesisMatching(expression3))
    {
        printf("Expression 3 is balanced\n");
    }
    else
    {
        printf("Expression 3 is not balanced\n");
    }

    return 0;
}
