// Write a recursive program to find the factorial value of given number.
#include <stdio.h>

long int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

int main()
{
    int num;
    printf("\n");
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0)
    {
        printf("Factorial is not defined for negative numbers.\n");
    }
    else
    {
        unsigned long long fact = factorial(num);
        printf("Factorial of %d is %ld\n", num, fact);
    }
    printf("\n\n");
    return 0;
}
