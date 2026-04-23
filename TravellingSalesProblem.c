#include <stdio.h>
#include <limits.h>

#define MAXN 15
#define INF INT_MAX

int n;                          // Number of cities
int d[MAXN][MAXN];              // Cost matrix
int dp[MAXN][1 << MAXN];        // DP table for memoization

// Function to calculate minimum cost
int g(int i, int S)
{
    // Base case: if all cities are visited, return cost to go back to start (city 0)
    if (S == 0)
    {
        return d[i][0];
    }

    // If already computed, return stored value
    if (dp[i][S] != -1)
    {
        return dp[i][S];
    }

    int mincost = INF;

    // Try visiting all cities in set S
    for (int k = 0; k < n; k++)
    {
        // Check if city k is in set S
        if (S & (1 << k))
        {
            // Cost = current to k + remaining path
            int cost = d[i][k] + g(k, S & ~(1 << k));

            // Update minimum cost
            if (cost < mincost)
            {
                mincost = cost;
            }
        }
    }

    // Store result in DP table
    return dp[i][S] = mincost;
}

int main()
{
    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &d[i][j]);
        }
    }

    // Initialize DP table with -1 (not computed)
    for (int i = 0; i < n; i++)
    {
        for (int mask = 0; mask < (1 << n); mask++)
        {
            dp[i][mask] = -1;
        }
    }

    // Create set of cities except starting city (0)
    int S = 0;
    for (int i = 1; i < n; i++)
    {
        S |= (1 << i);
    }

    // Compute result starting from city 0
    int result = g(0, S);

    // Display cost matrix
    printf("\nGiven cost matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }

    // Print final result
    printf("\nMinimum travelling cost = %d\n", result);

    return 0;
}