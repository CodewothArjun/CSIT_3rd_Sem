#include <stdio.h>

// Recursive function to find the nth Fibonacci number
int fibonacci(int n)
{
    // Base cases:
    // If n is 0 or 1, return n
    if (n == 0 || n == 1)
    {
        return n;
    }
    // Recursive case:
    // Fibonacci(n) = Fibonacci(n-1) + Fibonacci(n-2)
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{
    int n;
    printf("Enter the value of n for Fibonacci sequence: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Fibonacci sequence is not defined for negative numbers.\n");
    }
    else
    {
        printf("Fibonacci sequence up to %d terms:\n", n);
        for (int i = 0; i < n; i++)
        {
            printf("%d ", fibonacci(i));
        }
        printf("\n");
    }
printf("\n");
    return 0;
}
