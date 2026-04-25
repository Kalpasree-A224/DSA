#include <stdio.h>

#define V 5   // Number of vertices in the graph

// Function to find approximate vertex cover
void findVertexCover(int graph[V][V])
{
    int visited[V];

    // Initialize all vertices as not visited
    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
    }

    // Traverse all edges
    for (int u = 0; u < V; u++)
    {
        for (int v = 0; v < V; v++)
        {
            // If there is an edge and both vertices are not visited
            if (graph[u][v] == 1 && !visited[u] && !visited[v])
            {
                // Mark both vertices as visited (include in vertex cover)
                visited[u] = 1;
                visited[v] = 1;
            }
        }
    }

    printf("Approximate Vertex Cover is:\n");

    int count = 0;

    // Print selected vertices
    for (int i = 0; i < V; i++)
    {
        if (visited[i])
        {
            printf("%d ", i);
            count++;
        }
    }

    printf("\nTotal vertices in the cover: %d\n", count);
}

int main()
{
    // Adjacency matrix representation of graph
    int graph[V][V] = {
        {0, 1, 0, 0, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };

    printf("Executing Vertex Cover Approximation...\n");

    // Call function
    findVertexCover(graph);

    return 0;
}