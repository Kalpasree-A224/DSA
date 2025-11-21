#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
struct Node 
{
    int data;              // The value stored in this node
    struct Node *left;     // Pointer to the left child
    struct Node *right;    // Pointer to the right child
};

// Create a new node having the given value
struct Node *createNode(int value) 
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode) 
    {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE); // Exit or handle error
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a value into the BST and return the (possibly changed) root
struct Node *insert(struct Node *root, int value) 
{
    // If tree is empty, the new node becomes the root
    if (root == NULL) 
    {
        return createNode(value);
    }

    // Otherwise, recur down the tree
    if (value < root->data)
    {
        // Insert in left subtree
        root->left = insert(root->left, value);
    } 
    else 
    {
        // Insert in right subtree (you could also handle equal case specially if needed)
        root->right = insert(root->right, value);
    }

    return root; // Return the (unchanged) root pointer
}

// Preorder traversal: Root -> Left -> Right
void preorder(struct Node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);   // Visit root
    preorder(root->left);        // Traverse left subtree
    preorder(root->right);       // Traverse right subtree
}

// Inorder traversal: Left -> Root -> Right
void inorder(struct Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);          // Visit left subtree
    printf("%d ", root->data);    // Visit root
    inorder(root->right);         // Visit right subtree
}

// Postorder traversal: Left -> Right -> Root
void postorder(struct Node *root) 
{
    if (root == NULL)
        return;

    postorder(root->left);        // Traverse left subtree
    postorder(root->right);       // Traverse right subtree
    printf("%d ", root->data);    // Visit root
}

int main() 
{
    int n, value;
    struct Node *root = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insert(root, value);  // Insert value into BST
    }

    printf("Preorder Traversal: ");
    preorder(root);

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    printf("\n");
    return 0;
}
