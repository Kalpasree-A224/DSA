#include <stdio.h>

// Function to calculate nth Fibonacci number using recursion
int fib(int n)
{
    // Base case: if n is 0, return 0
    if (n == 0)
    {
        return 0;
    }

    // Base case: if n is 1, return 1
    if (n == 1)
    {
        return 1;
    }

    // Recursive case: fib(n) = fib(n-1) + fib(n-2)
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n, res;

    // Ask user to enter value of n
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Check for invalid input (negative number)
    if (n < 0)
    {
        printf("Invalid input!\n");
        return 0;
    }

    // Call Fibonacci function
    res = fib(n);

    // Print the result
    printf("Nth Fibonacci term is: %d\n", res);

    return 0;
}
