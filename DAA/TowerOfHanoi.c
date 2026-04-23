#include <stdio.h>

// Function to solve Tower of Hanoi
void hanoi(int diskCount, char source, char auxiliary, char destination)
{
    // Base condition: if only one disk, move it directly
    if (diskCount == 1)
    {
        printf("\nMove disk 1 from %c to %c", source, destination);
        return;
    }

    // Step 1: Move n-1 disks from source to auxiliary
    hanoi(diskCount - 1, source, destination, auxiliary);

    // Step 2: Move the nth disk from source to destination
    printf("\nMove disk %d from %c to %c", diskCount, source, destination);

    // Step 3: Move n-1 disks from auxiliary to destination
    hanoi(diskCount - 1, auxiliary, source, destination);
}

int main()
{
    int n;

    // Taking input from user
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Calling the function
    hanoi(n, 'S', 'A', 'D');  // S = Source, A = Auxiliary, D = Destination

    return 0;
}
