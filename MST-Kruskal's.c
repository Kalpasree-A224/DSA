#include <stdio.h>

#define V 5   // Number of vertices
#define E 6   // Number of edges

int parent[V];  // Array to store parent of each node

// Function to find the leader (root) of a set
int findLeader(int v)
{
    while (parent[v] != v)
    {
        v = parent[v];
    }
    return v;
}

// Function to merge two sets
void mergeSets(int u, int v)
{
    int a = findLeader(u);
    int b = findLeader(v);
    parent[a] = b;   // Attach one tree to another
}

// Function to sort edges based on weight (Bubble Sort)
void sortEdges(int edges[E][3])
{
    for (int i = 0; i < E - 1; i++)
    {
        for (int j = 0; j < E - i - 1; j++)
        {
            // Compare weights
            if (edges[j][2] > edges[j + 1][2])
            {
                // Swap entire edge (u, v, w)
                for (int k = 0; k < 3; k++)
                {
                    int temp = edges[j][k];
                    edges[j][k] = edges[j + 1][k];
                    edges[j + 1][k] = temp;
                }
            }
        }
    }
}

// Kruskal's Algorithm
void kruskal(int edges[E][3])
{
    sortEdges(edges);   // Step 1: Sort edges by weight

    // Initialize each vertex as its own parent
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
    }

    int count = 0;  // Number of edges selected
    int cost = 0;   // Total cost of MST

    printf("Selected edges in MST:\n");

    for (int i = 0; i < E; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        // Check if adding this edge forms a cycle
        if (findLeader(u) != findLeader(v))
        {
            printf("%d -- %d (weight = %d)\n", u, v, w);

            mergeSets(u, v);  // Union operation
            cost += w;
            count++;
        }

        // Stop when MST has V-1 edges
        if (count == V - 1)
            break;
    }

    printf("Total cost of MST = %d\n", cost);
}

int main()
{
    // Edge format: {u, v, weight}
    int edges[E][3] = {
        {0, 1, 2},
        {0, 2, 3},
        {1, 2, 5},
        {1, 3, 3},
        {2, 4, 4},
        {3, 4, 2}
    };

    kruskal(edges);

    return 0;
}