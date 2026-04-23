#include <stdio.h>
#include <stdlib.h>

#define V 5   // Number of vertices

// Function to find the vertex with minimum key value
int minKey(int key[], int visited[])
{
    int min = 999999;
    int min_index = -1;

    for (int i = 0; i < V; i++)
    {
        // Select the minimum key vertex not yet included in MST
        if (!visited[i] && key[i] < min)
        {
            min = key[i];
            min_index = i;
        }
    }

    return min_index;
}

// Function to print the constructed MST
void printMST(int parent[], int graph[V][V])
{
    printf("Edges \tWeight\n");
    int total = 0;

    for (int i = 1; i < V; i++)
    {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        total += graph[i][parent[i]];
    }

    printf("Total cost = %d\n", total);
}

// Function to construct and print MST using Prim's Algorithm
void primMST(int graph[V][V])
{
    int parent[V];   // Stores constructed MST
    int key[V];      // Key values to pick minimum weight edge
    int visited[V];  // To represent set of vertices included in MST

    // Step 1: Initialize all keys as infinite and visited as false
    for (int i = 0; i < V; i++)
    {
        key[i] = 999999;
        visited[i] = 0;
    }

    // Step 2: Start from vertex 0
    key[0] = 0;        // First vertex picked first
    parent[0] = -1;    // Root node has no parent

    // Step 3: Construct MST
    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, visited); // Pick minimum key vertex
        visited[u] = 1;               // Mark as visited

        // Update key and parent for adjacent vertices
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the MST
    printMST(parent, graph);
}

int main()
{
    // Adjacency matrix representation of graph
    int graph[V][V] = {
        {0, 2, 3, 0, 0},
        {2, 0, 5, 3, 0},
        {3, 5, 0, 0, 4},
        {0, 3, 0, 0, 2},
        {0, 0, 4, 2, 0}
    };

    primMST(graph);

    return 0;
}
