#include <stdio.h>

// Merge two sorted subarrays into one sorted array
// arr[]: the original array  
// left: starting index of left subarray  
// mid: ending index of left subarray (so left..mid is first sorted half)  
// right: ending index of right subarray (so mid+1..right is second sorted half)
void merge(int arr[], int left, int mid, int right)
{
    int i = left;        // pointer for left subarray
    int j = mid + 1;     // pointer for right subarray
    int k = 0;           // pointer for temp array

    // Temporary array to hold merged sorted values
    int temp[right - left + 1];

    // Merge elements from both halves in sorted order
    while (i <= mid && j <= right)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    // If there are leftover elements in left subarray, copy them
    while (i <= mid)
        temp[k++] = arr[i++];

    // If there are leftover elements in right subarray, copy them
    while (j <= right)
        temp[k++] = arr[j++];

    // Copy the merged elements back into the original array
    for (i = left, k = 0; i <= right; i++, k++)
        arr[i] = temp[k];
}

// Merge Sort: Recursively sort the array using divide and conquer
// arr[]: the array to sort  
// left: starting index of the subarray to sort  
// right: ending index of the subarray to sort  
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        // Find the middle point to divide the array into two halves
        int mid = (left + right) / 2;

        // Sort first half
        mergeSort(arr, left, mid);

        // Sort second half
        mergeSort(arr, mid + 1, right);

        // Merge the two sorted halves
        merge(arr, left, mid, right);
    }
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];  // Variable-length array (C99 feature; or you could malloc)
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Call mergeSort to sort the entire array
    mergeSort(arr, 0, n - 1);

    // Print the sorted array
    printf("Sorted array (Merge Sort): ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
