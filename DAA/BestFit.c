#include <stdio.h>

// Function to implement Best Fit algorithm
void bestfit(int items[], int n, int capacity)
{
    printf("\n--- Best Fit Algorithm ---\n");

    int bin[n];        // Stores remaining capacity of bins
    int bincount = 0;  // Number of bins used

    // Initialize all bins with full capacity
    for (int i = 0; i < n; i++)
    {
        bin[i] = capacity;
    }

    // Traverse each item
    for (int i = 0; i < n; i++)
    {
        int bestIndex = -1;           // Best bin index
        int minSpace = capacity + 1;  // Minimum space left after placing item

        // Check all existing bins
        for (int j = 0; j < bincount; j++)
        {
            // If item fits and leaves minimum space
            if (bin[j] >= items[i] && (bin[j] - items[i]) < minSpace)
            {
                bestIndex = j;
                minSpace = bin[j] - items[i];
            }
        }

        // If a suitable bin is found
        if (bestIndex != -1)
        {
            bin[bestIndex] -= items[i];
            printf("Item %d (size %d) placed in Bin %d\n",
                   i + 1, items[i], bestIndex + 1);
        }
        else
        {
            // Create new bin
            bin[bincount] = capacity - items[i];
            printf("Item %d (size %d) placed in Bin %d\n",
                   i + 1, items[i], bincount + 1);
            bincount++;
        }
    }

    // Display total bins used
    printf("\nTotal bins used = %d\n", bincount);
}

int main()
{
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int items[n];

    printf("Enter bin capacity: ");
    scanf("%d", &capacity);

    printf("Enter item sizes:\n");

    // Input item sizes
    for (int i = 0; i < n; i++)
    {
        int itemsize;

        printf("Item %d: ", i + 1);
        scanf("%d", &itemsize);

        // Validate item size
        if (itemsize > capacity)
        {
            printf("Error: Item size exceeds bin capacity. Re-enter.\n");
            i--; // Repeat this iteration
        }
        else
        {
            items[i] = itemsize;
        }
    }

    // Call Best Fit function
    bestfit(items, n, capacity);

    return 0;
}
