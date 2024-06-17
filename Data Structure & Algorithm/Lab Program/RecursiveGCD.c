// Write a recursive program to find a Fibonacci sequence.
#include <stdio.h>
int gcd(int a, int b)
{
    // Base case: If b is 0, return a
    if (b == 0)
    {
        return a;
    }

    // Recursive case: GCD(a, b) = GCD(b, a % b)
    else
    {
        return gcd(b, a % b);
    }
}

int main()
{
    int num1, num2;
    printf("Enter two numbers to find their GCD: ");
    scanf("%d %d", &num1, &num2);

    // Check for non-positive input
    if (num1 <= 0 || num2 <= 0)
    {
        printf("GCD is not defined for non-positive numbers.\n");
    }
    else
    {
        int result = gcd(num1, num2);
        printf("GCD of %d and %d is %d\n", num1, num2, result);
    }
    printf("\n\n");
    return 0;
}
