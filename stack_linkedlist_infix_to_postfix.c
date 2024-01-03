#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Function to get the precedence of an operator
int getOperatorPrecedence(char op)
{
    switch (op)
    {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char *infix, char *postfix)
{
    struct Stack myStack;
    initStack(&myStack);

    int i, j;
    for (i = 0, j = 0; infix[i] != '\0'; i++)
    {
        char currentChar = infix[i];

        if (isalnum(currentChar))
        {
            postfix[j++] = currentChar;
        }
        else if (currentChar == '(')
        {
            push(&myStack, currentChar);
        }
        else if (currentChar == ')')
        {
            while (!isEmpty(&myStack) && myStack.top->data != '(')
            {
                postfix[j++] = pop(&myStack);
            }
            if (!isEmpty(&myStack) && myStack.top->data == '(')
            {
                pop(&myStack); // Pop '('
            }
            else
            {
                fprintf(stderr, "Mismatched parentheses\n");
                exit(EXIT_FAILURE);
            }
        }
        else
        { // Operator
            while (!isEmpty(&myStack) && getOperatorPrecedence(myStack.top->data) >= getOperatorPrecedence(currentChar))
            {
                postfix[j++] = pop(&myStack);
            }
            push(&myStack, currentChar);
        }
    }

    // Pop remaining operators from the stack
    while (!isEmpty(&myStack))
    {
        if (myStack.top->data == '(')
        {
            fprintf(stderr, "Mismatched parentheses\n");
            exit(EXIT_FAILURE);
        }
        postfix[j++] = pop(&myStack);
    }

    postfix[j] = '\0';
}

int main()
{
    char infixExpression[100];
    char postfixExpression[100];

    printf("Enter an infix expression: ");
    scanf("%s", infixExpression);

    infixToPostfix(infixExpression, postfixExpression);

    printf("Postfix expression: %s\n", postfixExpression);

    return 0;
}
