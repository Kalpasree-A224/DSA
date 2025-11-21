#include <stdio.h>
#include <stdlib.h>

// Node structure for stack (singly linked list)
struct Node 
{
    int data;           // The data stored in the node
    struct Node *next;  // Pointer to the next node (below this in the stack)
};

/**
 * CreateNode: Creates a new node with the given data.
 * Returns the pointer to the newly allocated node.
 */
struct Node *CreateNode(int data) 
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {  // Check if malloc failed
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;  // Initially, no next node
    return newNode;
}

/**
 * push: Pushes a new element onto the top of the stack.
 * @top: pointer to the pointer to the top node (so we can modify it)
 * @data: value to push
 *
 * Creates a new node, links it in front of the current top, and updates top.
 * Time Complexity: O(1)
 */
void push(struct Node **top, int data)
{
    struct Node *newElement = CreateNode(data);
    if (!newElement) return;  // If memory allocation failed, do nothing

    // Insert the new node at the beginning of the linked list
    newElement->next = *top;
    *top = newElement;

    printf("Node with data %d pushed successfully.\n", data);
}

/**
 * pop: Pops (removes) the top element from the stack.
 * @top: pointer to the pointer to the top node
 *
 * If the stack is empty, prints an underflow message.
 * Otherwise, removes the top node, prints its value, and frees its memory.
 * Time Complexity: O(1)
 */
void pop(struct Node **top) 
{
    if (*top == NULL) 
    {
        // Underflow: no element to pop
        printf("Stack is empty/underflow, pop operation can't be performed.\n");
        return;
    }

    struct Node *temp = *top;       // Save current top
    *top = temp->next;              // Move top to the next node
    printf("Element %d popped from stack.\n", temp->data);
    free(temp);                      // Free memory of the popped node
}

/**
 * DisplayStack: Displays all elements in the stack from top to bottom.
 * @top: pointer to the top node
 *
 * Traverses the linked list from top, printing each node's data.
 */
void DisplayStack(struct Node *top)
{
    if (top == NULL)
    {
        printf("Stack is empty.\n");
        return;
    }

    struct Node *temp = top;
    printf("\nElements In Stack: [Top] ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");  // Indicate end of stack
}

int main()
{
    struct Node *top = NULL;  // Initialize stack as empty (top = NULL)
    int choice, data;

    while (1) 
    {
        // Menu for stack operations
        printf("\n--- Stack (Linked List) Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(&top, data);
                break;

            case 2:
                pop(&top);
                break;

            case 3:
                DisplayStack(top);
                break;

            case 4:
                printf("Exiting...\n");
                // Free all remaining nodes (optional, but good practice)
                while (top != NULL) 
                {
                    pop(&top);
                }
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
