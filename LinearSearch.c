#include<stdio.h>
#include<stdbool.h> // Header file to use the 'bool' data type

int main()
{
    // Declare variables
    int size;       // To store the size of the array
    int key;        // The element to be searched

    // 1. Get Array Size and Elements
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Declare the array with the user-defined size (Variable Length Array - VLA)
    int array[size];

    printf("Enter the array elements: ");
    // Loop to read elements into the array
    for(int i = 0; i < size; i++) 
    {
        scanf("%d", &array[i]);
    }

    // 2. Get Search Key
    printf("Enter the element to be search: ");
    scanf("%d", &key);

    // 3. Initialize Search Flag
    // The 'flag' is used to track if the element has been found or not.
    bool flag;
    flag = false;

    // 4. Linear Search Loop
    // Iterate through the array from the first element (index 0) to the last.
    for(int i = 0; i < size; i++) 
    {
        // Check if the current array element matches the key
        if(array[i] == key) 
        {
            // Element found! Print the index and the value.
            printf("The element is found at index of %d: %d\n", i, array[i]);
            // Set the flag to true
            flag = true;
            // Exit the loop immediately since the element has been found (Optimization)
            break;
        }
    }

    // 5. Element Not Found Check
    // If the loop finished and the flag is still false, the element was not present.
    if(!flag)
    {
        printf("The element is not found\n");
    }

    return 0; // Exit the program successfully
}