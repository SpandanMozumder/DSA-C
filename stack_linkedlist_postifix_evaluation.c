#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Stack structure
struct Stack
{
    int *array;
    int top;
    int capacity;
};

// Function to initialize an empty stack
void initStack(struct Stack *stack, int capacity)
{
    stack->array = (int *)malloc(capacity * sizeof(int));
    if (stack->array == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    stack->top = -1;
    stack->capacity = capacity;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, int data)
{
    if (isFull(stack))
    {
        fprintf(stderr, "Stack is full. Cannot push.\n");
        exit(EXIT_FAILURE);
    }
    stack->array[++stack->top] = data;
}

// Function to pop an element from the stack
int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        fprintf(stderr, "Stack is empty. Cannot pop.\n");
        exit(EXIT_FAILURE);
    }
    return stack->array[stack->top--];
}

// Function to evaluate a postfix expression
int evaluatePostfix(char postfix[])
{
    struct Stack stack;
    int operand1, operand2;

    int i = 0;
    while (postfix[i] != '\0')
    {
        if (isdigit(postfix[i]))
        {
            push(&stack, postfix[i] - '0'); // Convert character to integer
        }
        else
        {
            operand2 = pop(&stack);
            operand1 = pop(&stack);
            switch (postfix[i])
            {
            case '+':
                push(&stack, operand1 + operand2);
                break;
            case '-':
                push(&stack, operand1 - operand2);
                break;
            case '*':
                push(&stack, operand1 * operand2);
                break;
            case '/':
                if (operand2 != 0)
                {
                    push(&stack, operand1 / operand2);
                }
                else
                {
                    fprintf(stderr, "Error: Division by zero\n");
                    exit(EXIT_FAILURE);
                }
                break;
            default:
                fprintf(stderr, "Error: Invalid operator\n");
                exit(EXIT_FAILURE);
            }
        }
        i++;
    }

    if (!isEmpty(&stack) && stack.top == 0)
    {
        return pop(&stack);
    }
    else
    {
        fprintf(stderr, "Error: Malformed postfix expression\n");
        exit(EXIT_FAILURE);
    }
}

int main()
{
    char postfixExpression[] = "23*5+";
    int result = evaluatePostfix(postfixExpression);

    printf("Result of the postfix expression: %d\n", result);

    return 0;
}
