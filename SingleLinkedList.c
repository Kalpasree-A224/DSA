#include <stdio.h>
#include <stdlib.h>

// Define a node of the singly linked list
struct Node
{
    int data;              // value stored in the node
    struct Node *next;     // pointer to the next node
};

// Create a new node with given data and return its address
struct Node *CreateNode(int data) 
{
    // Allocate memory for a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {   // Check if malloc failed
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;  // Set the data
    newNode->next = NULL;  // By default, next is NULL (end of list)
    return newNode;
}

// Insert a new node at the beginning (head) of the list
void InsertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = CreateNode(data);
    if (!newNode) return;  // Safety: if allocation failed, do nothing

    newNode->next = *head; // Link new node’s next to current head
    *head = newNode;       // Update head to point to new node

    printf("Node with data %d inserted at beginning successfully.\n", data);
}

// Insert a new node at the end (tail) of the list
void InsertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = CreateNode(data);
    if (!newNode) return;

    // If the list is empty, then new node becomes head
    if (*head == NULL) 
    {
        *head = newNode;
    } 
    else
    {
        // Otherwise, traverse to the end of list
        struct Node *temp = *head;
        while (temp->next != NULL) 
        {
            temp = temp->next;
        }
        // Link last node’s next to the new node
        temp->next = newNode;
    }

    printf("Node with data %d inserted at the end successfully.\n", data);
}

// Insert a new node at a specific position (1-based index)
void InsertAtPosition(struct Node **head, int data, int position) 
{
    // Position should be at least 1
    if (position < 1) 
    {
        printf("Invalid position!\n");
        return;
    }

    // If inserting at the first position, reuse InsertAtBeginning
    if (position == 1) 
    {
        InsertAtBeginning(head, data);
        return;
    }

    // Otherwise, find the node after which to insert
    struct Node *prev = *head;
    for (int k = 1; (k < position - 1 && prev != NULL); k++)
    {
        prev = prev->next;
    }

    // If prev is NULL here, position is out of range
    if (prev == NULL) 
    {
        printf("Given position is out of range!\n");
        return;
    }

    // Create the new node and insert it
    struct Node *newNode = CreateNode(data);
    if (!newNode) return;

    newNode->next = prev->next;
    prev->next = newNode;

    printf("Node with data %d inserted at position %d successfully.\n", data, position);
}

// Delete a node by its value (first occurrence)
void DeleteNode(struct Node **head, int valueToDelete)
{
    // If list is empty, nothing to delete
    if (*head == NULL) 
    {
        printf("Linked List is empty, deletion operation can't be performed.\n");
        return;
    }

    struct Node *temp = *head;

    // Special case: if head itself has the value
    if (temp->data == valueToDelete) 
    {
        *head = temp->next;  // Move head to next node
        free(temp);          // Free the old head
        printf("Data %d deleted from list.\n", valueToDelete);
        return;
    }

    // Otherwise, traverse to find the node whose next is the target
    struct Node *prev = *head;
    while (prev->next != NULL) 
    {
        if (prev->next->data == valueToDelete)
        {
            temp = prev->next;          // Node to delete
            prev->next = temp->next;    // Bypass the node
            free(temp);                 // Free its memory
            printf("Data %d deleted from list.\n", valueToDelete);
            return;
        }
        prev = prev->next;  // Move forward
    }

    // If we reach here, value was not found
    printf("Element %d not found.\n", valueToDelete);
}

// Display all nodes of the linked list, with addresses for clarity
void DisplayList(struct Node *head)
{
    if (head == NULL) 
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("\nLinked List Nodes: ");
    while (temp != NULL)
    {
        // Print the pointer address, value, and next pointer
        printf(" |At=%p|%d|Next=%p| -> ", (void*)temp, temp->data, (void*)temp->next);
        temp = temp->next;
    }
    // Optionally: printf("NULL\n");
}

// Main function: menu-driven interface to operate on the linked list
int main() 
{
    struct Node *head = NULL;  // Initialize head pointer to NULL (empty list)
    int choice, data, pos;

    while (1) 
    {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete by Value\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                InsertAtBeginning(&head, data);
                break;

            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                InsertAtEnd(&head, data);
                break;

            case 3:
                printf("Enter data and position to insert: ");
                scanf("%d %d", &data, &pos);
                InsertAtPosition(&head, data, pos);
                break;

            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &data);
                DeleteNode(&head, data);
                break;

            case 5:
                DisplayList(head);
                break;

            case 6:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
