#include <stdio.h>
#include <stdlib.h>

// Swap two integers by reference (so the changes persist)
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function (Lomuto partition scheme)
// - list[]: the array to partition  
// - low, high: the subarray boundaries  
// Returns the final index of the pivot
int partition(int list[], int low, int high)
{
    // Choose the pivot as the last element in current subarray
    int pivot = list[high];
    // i will mark the boundary for elements less than pivot
    int i = low - 1;

    // Traverse from low to high-1
    for (int j = low; j < high; j++)
    {
        // If current element is less than the pivot
        if (list[j] < pivot)
        {
            i++;
            // Swap list[i] and list[j] so that element < pivot goes to left part
            swap(&list[i], &list[j]);
        }
    }

    // Finally, put the pivot in its correct position (i+1)
    swap(&list[i + 1], &list[high]);
    return i + 1;
}

// Quick Sort recursive function
// Sorts list[low .. high]
void quickSort(int list[], int low, int high)
{
    if (low < high)
    {
        // Partition the array and get pivot index
        int pi = partition(list, low, high);

        // Recursively sort elements before pivot
        quickSort(list, low, pi - 1);

        // Recursively sort elements after pivot
        quickSort(list, pi + 1, high);
    }
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Variable length array (C99+); alternatively use malloc
    int list[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &list[i]);

    // Call Quick Sort on the whole array
    quickSort(list, 0, n - 1);

    // Print the sorted array
    printf("Sorted array (Quick Sort): ");
    for (int i = 0; i < n; i++)
        printf("%d ", list[i]);
    printf("\n");

    return 0;
}
