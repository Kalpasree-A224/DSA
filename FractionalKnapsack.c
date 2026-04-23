#include <stdio.h>

// Structure to store item details
struct item 
{
    int weight;
    int value;
    float ppw;   // profit per weight (value/weight)
};

// Function to sort items based on ppw in descending order
void sort(struct item items[], int n) 
{
    struct item temp;

    // Bubble sort
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)   // corrected condition
        {
            // Swap if next item has higher ratio
            if(items[j].ppw < items[j + 1].ppw)
            {
                temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }

    // Display sorted items
    printf("\nItems sorted by value/weight ratio:\n");
    for(int i = 0; i < n; i++)
    {
        printf("Item %d: weight=%d, value=%d, ratio=%.2f\n",
               i + 1, items[i].weight, items[i].value, items[i].ppw);
    }
}

int main() 
{
    int n;
    float capacity;

    printf("Enter the no.of items: ");
    scanf("%d", &n);

    // Check for valid input
    if(n <= 0)
        return 1;

    struct item items[n];

    printf("Enter the weights and values of each item:\n");

    // Input items
    for(int i = 0; i < n; i++)
    {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);

        // Calculate profit per weight (typecasting to avoid integer division)
        items[i].ppw = (float)items[i].value / items[i].weight;
    }

    printf("Enter the knapsack capacity: ");
    scanf("%f", &capacity);

    // Sort items based on ratio
    sort(items, n);

    float totalprofit = 0.0;

    // Apply fractional knapsack logic
    for(int i = 0; i < n; i++)
    {
        // If item can be fully included
        if(capacity >= items[i].weight)
        {
            totalprofit += items[i].value;
            capacity -= items[i].weight;
        }
        else
        {
            // Take fractional part of the item
            totalprofit += items[i].ppw * capacity;   // corrected
            break;
        }
    }

    // Display final result
    printf("\nTotal Profit = %.2f\n", totalprofit);

    return 0;
}