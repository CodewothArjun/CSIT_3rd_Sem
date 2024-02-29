/*
// factorial
#include <stdio.h>
long int factorial(int n)
{
    if (n == 1)
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
    int n = 5;
    printf("Factorial of %d is %d", n, factorial(n));
    return 0;
}*/

// fibo series
#include <stdio.h>

int fibo(int k)
{
    if (k == 0)
    {
        return 0;
    }
    else if (k == 1)
    {
        return 1;
    }
    else
    {
        return fibo(k - 1) + fibo(k - 2);
    }
}

int main()
{
    int n = 6, i;
    printf("Fibo series:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", fibo(i));
    }
    return 0;
}