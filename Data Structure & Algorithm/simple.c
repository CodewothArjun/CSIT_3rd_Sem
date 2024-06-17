/*
#include <stdio.h>
int main()
{
    int i, a = 0, b = 1, c, n;
    printf("Enter the no. of fabinnaci series: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a);
        c = a + b;
        a = b;
        b = c;
    }

    return 0;
}
*/
#include <stdio.h>
int main()
{
    int i, j, n, factorial = 1;
    printf("Enter a number to calculate the factorial of a number: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        factorial = factorial * i;
    }
    printf("Factorial of a %d is %d", n, factorial);

    return 0;
}