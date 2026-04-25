#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function (Lomuto partition scheme)
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];   // Choose last element as pivot
    int i = low - 1;         // Index of smaller element

    for (int j = low; j < high; j++)
    {
        // If current element is smaller than pivot
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);  // Swap elements
        }
    }

    // Place pivot in correct position
    swap(&arr[i + 1], &arr[high]);

    return i + 1; // Return pivot index
}

// Quick Sort function
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        // Generate random pivot index
        int randomIndex = low + rand() % (high - low + 1);

        // Swap random pivot with last element
        swap(&arr[randomIndex], &arr[high]);

        // Partition the array
        int pi = partition(arr, low, high);

        // Recursively sort left and right subarrays
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main()
{
    int n;

    // Seed for random number generation
    srand(time(NULL));

    printf("Enter number of elements: ");
    
    // Input validation
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid input! Please enter a positive integer.\n");
        return 1;
    }

    int numbers[n];

    printf("Enter %d integers:\n", n);

    // Read array elements
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &numbers[i]);
    }

    // Call quicksort
    quicksort(numbers, 0, n - 1);

    // Print sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", numbers[i]);
    }

    return 0;
}