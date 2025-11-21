#include<stdio.h>

int main() 
{
    // Declare variables
    int size;       // To store the size of the array
    int key;        // The element to be searched
    int high;       // The upper bound/index of the search range
    int low;        // The lower bound/index of the search range
    int mid;        // The middle index of the current search range

    // 1. Get Array Size and Elements
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Declare the array with the user-defined size (Variable Length Array - VLA)
    int array[size];

    printf("Enter the elements into the array (must be sorted!): ");
    // Loop to read elements into the array
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }

    // 2. Get Search Key
    printf("Enter the element to be searched: ");
    scanf("%d", &key);

    // 3. Initialize Search Boundaries
    low = 0;            // Start with the first index
    high = size - 1;    // End with the last index

    // 4. Binary Search Loop
    // Continue searching as long as the lower bound does not exceed the upper bound
    while(low <= high) 
    {
        // Calculate the middle index
        // mid = (low + high) / 2; (Using this form is simpler but can cause integer overflow for very large arrays)
        mid = low + (high - low) / 2; // A safer way to calculate mid

        // Case 1: Key is found at the middle index
        if(array[mid] == key)
        {
            // Print the position (index) where the element is found
            printf("Element is found at the position: %d\n", mid);
            return 0; // Exit the program successfully
        }
        
        // Case 2: Key is greater than the middle element
        if(array[mid] < key) 
        {
            // Since the array is sorted, the key must be in the upper half.
            // Move the lower bound to mid + 1 to search the right subarray.
            low = mid + 1;
        }
        // Case 3: Key is smaller than the middle element
        else 
        { // array[mid] > key
            // The key must be in the lower half.
            // Move the upper bound to mid - 1 to search the left subarray.
            high = mid - 1;
        }
    }

    // 5. Element Not Found
    // If the loop finishes without finding the key, it means low > high.
    // The key is not present in the array.
    printf("Element not found. Please enter the correct element to search.\n");
    return 0; // Exit the program
}