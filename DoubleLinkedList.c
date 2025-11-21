#include <stdio.h>
#include <stdlib.h>

// Define a node of a doubly linked list
struct Node 
{
    int data;               // Data stored in this node
    struct Node *next;      // Pointer to the next node in the list
    struct Node *prev;      // Pointer to the previous node in the list
};

// Create a new node with the given data, return pointer to it
struct Node *CreateNode(int data) 
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {  // If malloc fails
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;   // Initially, no next node
    newNode->prev = NULL;   // Initially, no previous node
    return newNode;
}

// Insert a new node at the beginning (head) of the doubly linked list
void InsertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = CreateNode(data);
    if (!newNode) return;   // Safety: if allocation failed, abort

    // Link the new node to the current head
    newNode->next = *head;
    newNode->prev = NULL;   // New node will be first, so prev = NULL

    // If list was not empty, make current head's prev point to new node
    if (*head != NULL)
    {
        (*head)->prev = newNode;
    }

    // Update head to point to the new node
    *head = newNode;

    printf("Node with data %d inserted at beginning successfully.\n", data);
}

// Insert a new node at the end (tail) of the doubly linked list
void InsertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = CreateNode(data);
    if (!newNode) return;

    // If the list is currently empty, new node becomes the head
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        // Traverse to the last node
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        // temp is now the last node

        // Link the last node's next to new node
        temp->next = newNode;
        // Link the new node's prev to temp (bidirectional link)
        newNode->prev = temp;
    }

    printf("Node with data %d inserted at the end successfully.\n", data);
}

// Insert a new node at a given position (1-based) in the list
void InsertAtPosition(struct Node **head, int data, int position) 
{
    
    // Position indexing check
    if (position < 1) 
    {
        printf("Invalid position!\n");
        return;
    }

    // If position is 1, just insert at beginning
    if (position == 1) 
    {
        InsertAtBeginning(head, data);
        return;
    }

    // Traverse to the node after which insertion is to happen
    struct Node *temp = *head;
    for (int k = 1; (k < position - 1 && temp != NULL); k++) 
    {
        temp = temp->next;
    }

    // If temp is NULL, position is out of range
    if (temp == NULL)
    {
        printf("Given position is out of range!\n");
        return;
    }

    // Create the new node
    struct Node *newNode = CreateNode(data);
    if (!newNode) return;

    // Set up the new node's pointers
    newNode->next = temp->next;  // New node next = node currently after temp
    newNode->prev = temp;        // New node prev = temp

    // If not inserting at the end, fix the next node's prev pointer
    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }

    // Link temp's next to the new node
    temp->next = newNode;

    printf("Node with data %d inserted at position %d successfully.\n", data, position);
}

// Delete the first node found that has the given value
void DeleteNode(struct Node **head, int valueToDelete) 
{
    if (*head == NULL) 
    {
        printf("Linked List is empty, deletion operation can't be performed\n");
        return;
    }

    struct Node *temp = *head;

    // If the head node is the one to be deleted
    if (temp->data == valueToDelete)
    {
        *head = temp->next;      // Move head to the next node

        if (*head != NULL)
        {
            (*head)->prev = NULL;  // New head's prev becomes NULL
        }

        free(temp);               // Free memory of old head
        printf("Data %d deleted from list.\n", valueToDelete);
        return;
    }

    // Otherwise, find the node to delete
    struct Node *before = *head;
    while (before->next != NULL)
    {
        if (before->next->data == valueToDelete) 
        {
            temp = before->next;          // Node to delete

            // Bypass temp: link before -> temp->next
            before->next = temp->next;

            // If temp is not the last node, fix the prev link of next node
            if (temp->next != NULL)
            {
                temp->next->prev = before;
            }

            free(temp);   // Free memory
            printf("Data %d deleted from list.\n", valueToDelete);
            return;
        }
        before = before->next;
    }

    // If we reached the end and didn't find the value
    printf("Element %d not found.\n", valueToDelete);
}

// Display the list from head to tail, showing data and pointers
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
        // Print prev pointer, data, and next pointer for each node
        printf(" |Prev=%p|%d|Next=%p| -> ", (void*)temp->prev, temp->data, (void*)temp->next);
        temp = temp->next;
    }
    // Optionally, you can print "NULL" at the end
    // printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;  // Initialize empty list
    int choice, data, pos;

    while (1) 
    {
        // Menu for user operations
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete by Value\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
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
