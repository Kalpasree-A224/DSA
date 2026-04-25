#include <stdio.h>

#define V 5               // Number of vertices
#define INF 999999        // A large value representing infinity

/* 
   Function to find the vertex with minimum distance
   which is not yet visited
*/
int extractMin(int dist[], int visited[])
{
    int min = INF;
    int min_index = -1;

    // Check all vertices
    for (int v = 0; v < V; v++)
    {
        // Select the unvisited vertex with smallest distance
        if (!visited[v] && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

/*
   Dijkstra's Algorithm Function
   Finds shortest distance from source vertex 0
*/
void dijkstra(int graph[V][V])
{
    int dist[V];        // Stores shortest distance from source
    int visited[V];     // Tracks visited vertices

    // Initialize all distances as INF and visited as 0
    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    // Distance of source vertex from itself is 0
    dist[0] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V; count++)
    {
        // Pick the minimum distance vertex
        int u = extractMin(dist, visited);

        // If no vertex is found, stop
        if (u == -1)
            break;

        // Mark selected vertex as visited
        visited[u] = 1;

        // Update distance value of adjacent vertices
        for (int j = 0; j < V; j++)
        {
            /*
               Update dist[j] only if:
               1. There is an edge from u to j
               2. j is not visited
               3. New path is shorter than current distance
            */
            if (graph[u][j] > 0 && !visited[j])
            {
                if (dist[j] > dist[u] + graph[u][j])
                {
                    dist[j] = dist[u] + graph[u][j];
                }
            }
        }
    }

    // Print final shortest distances
    printf("Vertex \t Distance from Source (0)\n");

    for (int i = 0; i < V; i++)
    {
        printf("%d --> %d\n", i, dist[i]);
    }
}

int main()
{
    // Adjacency matrix representation of graph
    int graph[V][V] =
    {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    // Call Dijkstra's algorithm
    dijkstra(graph);

    return 0;
}