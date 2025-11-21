#include <stdio.h>
#include <stdlib.h>

// We'll use a global queue of pointers to tree nodes, and front / rear indices
struct Node **queue;
int front = -1, rear = -1, MAX;

// Structure for a binary tree node
// It has `data`, and pointers to left and right children.
struct Node 
{
    int data;
    struct Node *left, *right;
};

// Create a new tree node with given value
struct Node *createNode(int value) 
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a value into the binary tree (BST style) and return the (possibly changed) root
struct Node *insert(struct Node *root, int value) 
{
    if (root == NULL)
    {
        // If tree is empty or we have reached a leaf position, make a new node
        return createNode(value);
    }
    if (value < root->data)
    {
        // Insert into left subtree
        root->left = insert(root->left, value);
    }
    else
    {
        // Insert into right subtree
        root->right = insert(root->right, value);
    }
    return root;
}

// Enqueue a tree node pointer into the queue for BFS
void enqueue(struct Node *temp) 
{
    // If queue is already full, do nothing
    if (rear == MAX - 1)
    {
        return;
    }
    // If queue was empty, reset front to 0
    if (front == -1) 
    {
        front = 0;
    }
    // Add the node to queue and increment rear
    queue[++rear] = temp;
}

// Dequeue a tree node pointer from the queue
struct Node *dequeue() 
{
    // If queue is empty (no elements to dequeue)
    if (front == -1 || front > rear)
    {
        return NULL;
    }
    // Return the front element and advance front
    return queue[front++];
}

// Level Order Traversal (BFS) of the tree
void levelOrder(struct Node *root) 
{
    if (root == NULL) 
    {
        return; // Nothing to traverse
    }

    // Start by enqueuing the root node
    enqueue(root);

    // Continue until we have processed all enqueued nodes
    while (front <= rear) 
    {
        struct Node *current = dequeue();
        if (current == NULL)
        {
            // Safety check (should rarely happen in correct usage)
            continue;
        }

        // Print the current node's data
        printf("%d ", current->data);

        // Enqueue its left child, if any
        if (current->left != NULL) 
        {
            enqueue(current->left);
        }

        // Enqueue its right child, if any
        if (current->right != NULL)
        {
            enqueue(current->right);
        }
    }
}

int main() 
{
    struct Node *root = NULL;
    int value;

    // Use `MAX` both as number of elements in the tree 
    // and queue size (simple approach)
    printf("Enter number of elements: ");
    scanf("%d", &MAX);

    // Allocate the queue (array of pointers to Node)
    queue = (struct Node **)malloc(MAX * sizeof(struct Node *));
    if (!queue) 
    {
        printf("Queue memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter %d values:\n", MAX);
    for (int i = 0; i < MAX; i++)
    {
        scanf("%d", &value);
        root = insert(root, value);  // Insert into BST
    }

    printf("\nLevel Order Traversal: ");
    levelOrder(root);
    printf("\n");

    // (Optional) free memory: you might write a tree-free function, and also free the queue
    free(queue);

    return 0;
}
