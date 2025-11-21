#include <stdio.h>
#include <stdlib.h> // For malloc

// Global variables for queue management
int Size;        // Stores the size of the queue (to be read from user)
int front = -1;  // Index of the front element
int rear = -1;   // Index of the rear element
int *q;          // Pointer to the dynamically allocated queue array

// Function to add an element to the circular queue
void enqueue(int item) 
{
    // Check for Queue Overflow condition
    // Queue is full if (rear + 1) % Size == front
    if ((rear + 1) % Size == front) 
    {
        printf("Queue Overflow!\n");
        return;
    }

    // If the queue is initially empty (first insertion)
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        // Calculate the new rear position using the modulo operator
        rear = (rear + 1) % Size;
    }

    // Insert the item at the new rear position
    q[rear] = item;
    printf("Item added to the queue: %d\n", q[rear]);
}

// Function to remove an element from the circular queue
int dequeue()
{
    int item; // To store the dequeued item

    // Check for Queue Underflow condition
    if (front == -1)
    {
        printf("Queue Underflow!\n");
        return -1; // Return -1 to indicate failure/empty queue
    }

    // Get the item at the front of the queue
    item = q[front];

    // If there was only one element in the queue
    if (front == rear)
    {
        // Reset front and rear to -1 (empty state)
        front = -1;
        rear = -1;
    } 
    else
    {
        // Calculate the new front position using the modulo operator
        front = (front + 1) % Size;
    }

    // Return the dequeued item
    return item;
}

// Main function to drive the circular queue operations
int main() {
    int op = 0;
    int item;

    // Get the desired size of the queue from the user
    printf("Enter the size of the queue: ");
    scanf("%d", &Size);

    // Dynamically allocate memory for the queue array
    // Size * sizeof(int) bytes
    q = (int *)malloc(Size * sizeof(int));

    // Loop until the user chooses to exit (Option 3)
    while (op != 3) 
    {
        // Display the menu of operations
        printf("\nChoose the operation: \n1. Enqueue \n2. Dequeue \n3. Exit \n");
        scanf("%d", &op);

        // Perform the selected operation
        switch (op)
        {
            case 1: // Enqueue operation
                printf("Enter number to enqueue: ");
                scanf("%d", &item);
                enqueue(item);
                break;

            case 2: // Dequeue operation
                item = dequeue();
                if (item != -1)
                { // Check if dequeue was successful (not underflow)
                    printf("Deleted Item: %d\n", item);
                }
                break;

            case 3: // Exit operation
                printf("Exiting program.\n");
                // Free dynamically allocated memory
                free(q);
                return 0; // Exit successfully
                break; // Optional break, as return 0 is executed

            default: // Invalid input
                printf("Incorrect operation selection\n");
                break;
        }
    }
    
    // In case the loop condition is changed, this return is a good safeguard
    return 0;
}