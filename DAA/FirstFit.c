#include <stdio.h>

// Function to implement First Fit algorithm
void firstfit(int items[], int n, int capacity)
{
    int bin[n];        // Stores remaining capacity of each bin
    int bincount = 0;  // Number of bins used

    printf("\n--- Executing First Fit Algorithm ---\n");

    // Initialize all bins with 0 (no bins used initially)
    for (int i = 0; i < n; i++)
    {
        bin[i] = 0;
    }

    // Traverse each item
    for (int i = 0; i < n; i++)
    {
        // If item size exceeds bin capacity
        if (items[i] > capacity)
        {
            printf("Item %d with size %d cannot be placed in any bin\n",
                   i + 1, items[i]);
            continue;
        }

        int placed = 0; // Flag to check if item is placed

        // Try to place item in existing bins (First Fit)
        for (int j = 0; j < bincount; j++)
        {
            if (bin[j] >= items[i]) // Check if item fits
            {
                bin[j] -= items[i]; // Reduce remaining capacity
                printf("Item %d (size %d) placed in Bin %d\n",
                       i + 1, items[i], j + 1);

                placed = 1;
                break; // Stop after placing in first suitable bin
            }
        }

        // If item not placed, create a new bin
        if (!placed)
        {
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

    // Input item sizes
    printf("Enter item sizes:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Item %d: ", i + 1);
        scanf("%d", &items[i]);
    }

    // Input bin capacity
    printf("Enter bin capacity: ");
    scanf("%d", &capacity);

    // Call First Fit function
    firstfit(items, n, capacity);

    return 0;
}
