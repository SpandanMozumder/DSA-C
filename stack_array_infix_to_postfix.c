#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct
{
    char stack[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *s)
{
    s->top = -1;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

void push(Stack *s, char c)
{
    if (s->top == MAX_SIZE - 1)
    {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    s->stack[++s->top] = c;
}

char pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->stack[s->top--];
}

int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int getPrecedence(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
    }
}

void infixToPostfix(char infix[], char postfix[])
{
    Stack stack;
    initialize(&stack);

    int i, j;
    i = j = 0;

    while (infix[i] != '\0')
    {
        if (isalnum(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else if (infix[i] == '(')
        {
            push(&stack, infix[i++]);
        }
        else if (infix[i] == ')')
        {
            while (!isEmpty(&stack) && stack.stack[stack.top] != '(')
            {
                postfix[j++] = pop(&stack);
            }
            if (!isEmpty(&stack) && stack.stack[stack.top] == '(')
            {
                pop(&stack); // Discard '('
                i++;
            }
            else
            {
                printf("Invalid infix expression\n");
                exit(EXIT_FAILURE);
            }
        }
        else if (isOperator(infix[i]))
        {
            while (!isEmpty(&stack) && getPrecedence(stack.stack[stack.top]) >= getPrecedence(infix[i]))
            {
                postfix[j++] = pop(&stack);
            }
            push(&stack, infix[i++]);
        }
        else
        {
            printf("Invalid character in infix expression: %c\n", infix[i]);
            exit(EXIT_FAILURE);
        }
    }

    while (!isEmpty(&stack))
    {
        if (stack.stack[stack.top] == '(')
        {
            printf("Invalid infix expression\n");
            exit(EXIT_FAILURE);
        }
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
}

int main()
{
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
