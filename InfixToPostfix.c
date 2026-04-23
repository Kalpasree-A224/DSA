#include <stdio.h>
#include <stdlib.h>

// Global stack variables
int top = -1, max;
char *stack;

// Push element on stack
void push(char item)
{
    // Check for stack overflow
    if (top == max - 1)
    {
        printf("Stack overflow!");
    } 
    else
    {
        top = top + 1;
        stack[top] = item;
    }
}

// Pop element from stack
char pop()
{
    // Check for stack underflow
    if (top == -1)
    {
        printf("Stack is empty!");
        return '\0';
    } 
    else 
    {
        char item = stack[top];
        top = top - 1;
        return item;
    }
}

// Peek top element of stack (without removing)
char peek()
{
    if (top == -1)
    {
        return '\0';
    } 
    else
    {
        return stack[top];
    }
}

// Get precedence of operators
int getprecedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

int main() {
    // Read maximum size of the expression
    printf("Enter the size expression: ");
    scanf("%d", &max);

    // Memory allocation for stack and expressions
    stack = (char *)malloc(max * sizeof(char));
    char infix[max], postfix[max];

    // Read infix expression from user
    printf("Enter the expression: ");
    scanf("%s", infix);

    int tokenprecedence, i = 0, j = 0;
    char temp;

    // Loop through the infix expression
    while ((temp = infix[i]) != '\0') 
    {
        tokenprecedence = getprecedence(temp);

        if (tokenprecedence > 0) 
        {  // If operator is encountered
            while (tokenprecedence <= getprecedence(peek()))
            {
                postfix[j++] = pop();
            }
            push(temp);
        }
        else
        {  // If operand or parenthesis is encountered
            switch (temp) 
            {
                case '(':
                    push(temp);
                    break;
                case ')':
                    while (peek() != '(') {
                        postfix[j++] = pop();
                    }
                    pop();  // Remove '(' from stack
                    break;
                default:
                    postfix[j++] = temp;
                    break;
            }
        }
        i++;
    }

    // Pop remaining operators from stack
    while (peek() != '\0') {
        char c = pop();
        postfix[j++] = c;
    }
    postfix[j] = '\0';  // Null terminate the postfix expression

    printf("Postfix notation is : %s", postfix);
    return 0;
}
