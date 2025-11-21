#include <stdio.h>

int top = -1;     // top initialized to -1 (stack is empty)
int size;            // size of the stack

// ---------------- DISPLAY FUNCTION ----------------
void display(int arr[])
{
    printf("\nCurrent stack elements are:\n");

    // Loop from top to bottom to show stack
    for(int i = top; i >= 0; i--)
    {
        printf("%d ", arr[i]);   // print each element
    }

    printf(" <-- top\n");        // indicate top of stack
}


// ---------------- PUSH FUNCTION ----------------
void push(int arr[])
{
    int item;

    // Check for stack overflow
    if(top == size - 1)
    {
        printf("\nStack Overflow\n");
    }
    else
    {
        printf("Enter the element to be inserted: ");
        scanf("%d", &item);

        top = top + 1;       // increment top
        arr[top] = item;     // insert element at top

        printf("Item pushed successfully.\n");
    }
}


// ---------------- POP FUNCTION ----------------
void pop(int arr[])
{
    int item;

    // Check for stack underflow
    if(top == -1)
    {
        printf("\nStack Underflow\n");
    }
    else
    {
        item = arr[top];      // store top element
        top = top - 1;        // decrease top

        printf("The item popped is: %d\n", item);
    }
}


// ---------------- MAIN FUNCTION ----------------
int main()
{
    int op;                   // to store user operation

    printf("Enter the size of the stack: ");
    scanf("%d", &size);

    int arr[size];               // stack array declared with size n

    while(op != 3)            // menu repeats until op = 3
    {
        printf("\nChoose the operation:\n1. PUSH\n2. POP\n3. EXIT\n");
        scanf("%d", &op);

        switch(op)
        {
            case 1:
                push(arr);        // call push
                display(arr);     // show the stack
                break;

            case 2:
                pop(arr);         // call pop
                display(arr);     // display updated stack
                break;

            case 3:
                return 0;         // exit program

            default:
                printf("Incorrect Operation Selected\n");
                break;
        }
    }

    return 0;
}