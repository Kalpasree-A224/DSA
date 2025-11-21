#include <stdio.h>      // header file for input/output
#include <stdlib.h>     // header file for malloc()

int top = -1, max;      // top = -1 means stack is empty, max = size of stack
char *stack;            // stack declared as character pointer

// ---------------- PUSH FUNCTION ----------------
void push(char item)
{
    if(top == max - 1)        // check if stack is full
    {
        printf("Stack is overflow\n");    // display overflow message
    }
    else
    {
        top = top + 1;        // increment top
        stack[top] = item;    // place item on stack
    }
}

// ---------------- POP FUNCTION ----------------
char pop()
{
    char item;

    if(top == -1)             // check if stack is empty
    {
        printf("Stack underflow\n");  
        return '\0';          // return null if underflow
    }
    else
    {
        item = stack[top];    // take topmost element
        top = top - 1;        // decrement top
        return item;          // return popped element
    }
}


// ---------------- MAIN FUNCTION ----------------
int main()
{
    printf("Enter the size of string to reverse: ");
    scanf("%d", &max);                     // read string size

    char stringToReverse[max];             // array to store input string

    stack = (char*) malloc(max * sizeof(char));   // dynamic memory allocation for stack

    printf("Please enter the string of size %d to reverse: ", max);
    scanf("%s", stringToReverse);          // read the string

    // push each character into stack
    for(int i = 0; i < max; i++)
    {
        push(stringToReverse[i]);
    }

    // popping characters gives reversed string
    printf("Reversed string: ");
    for(int i = 0; i < max; i++)
    {
        printf("%c", pop());               // print popped characters
    }

    return 0;            // end of program
}