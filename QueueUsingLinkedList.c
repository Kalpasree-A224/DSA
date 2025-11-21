#include <stdio.h>
#include <stdlib.h>

// Node structure for the queue (singly linked list)
struct Node 
{
    int data;           // Data stored in this node
    struct Node *next;  // Pointer to the next node
};

// Global pointers for front and rear of the queue
struct Node *front = NULL;
struct Node *rear = NULL;

/**
 * Enqueue operation: Insert an item into the circular queue.
 *
 * Creates a new node with the given data, and adjusts front/rear pointers.
 * Maintains the circular link: rear->next always points to front.
 */
void enqueue(int item) 
{
    // Allocate a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) 
    {
        // Memory allocation failed
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = item;
    newNode->next = NULL;

    // If the queue is empty: both front and rear are NULL
    if (front == NULL && rear == NULL)
    {
        front = rear = newNode;
        // For a single-node circular queue, next should point to itself
        newNode->next = front;
    }
    else
    {
        // Otherwise, link the new node at the end and move rear
        rear->next = newNode;
        rear = newNode;
        // Maintain circular property by pointing rear->next to front
        rear->next = front;
    }

    printf("%d inserted into circular queue.\n", item);
}

/**
 * Dequeue operation: Remove an item from the front of the queue.
 *
 * If there's only one node, reset front and rear to NULL.
 * Otherwise, move front forward and fix the circular link.
 */
void dequeue()
{
    if (front == NULL)
    {
        // Queue is empty
        printf("Queue Underflow!\n");
        return;
    }

    struct Node *temp = front;

    // If only one node in queue
    if (front == rear) 
    {
        front = rear = NULL;
    }
    else
    {
        // More than one node: move front to next node
        front = front->next;
        // Update rear->next to the new front to keep the circle
        rear->next = front;
    }

    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

/**
 * Display the elements of the circular queue.
 *
 * Traverses from front, printing data, until it loops back to front.
 */
void display()
{
    if (front == NULL) 
    {
        printf("Queue is empty.\n");
        return;
    }

    struct Node *temp = front;

    printf("Circular Queue elements: ");
    do 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);  // Stop when we come back to front

    printf("\n");
}

int main()
{
    int choice, data;

    while (1)
    {
        // Menu for queue operations
        printf("\n--- Queue Using Linked List Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                enqueue(data);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
