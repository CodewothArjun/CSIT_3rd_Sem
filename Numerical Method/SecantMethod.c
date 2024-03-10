// 3. Write a program to find the root of non-linear equation using Secant method.

#include <stdio.h>
#include <conio.h>
#include <math.h>
#define MAX 20
#define E 0.0001
#define f(x) (x * x - 4 * x - 10)
int main()
{
    int count = 1;
    float x1, x2, x3, f1, f2;
    printf("\nEnter two initial guess values: ");
    scanf("%f%f", &x1, &x2);
begin:
    f1 = f(x1);
    f2 = f(x2);
    x3 = x2 - f2 * (x2 - x1) / (f2 - f1);
    if (fabs((x3 - x2) / x3) < E)
    {
        printf("The root is %f", x3);
        printf("\nNo. of iterations is %d", count);
        printf("\n\n");
    }
    else
    {
        x1 = x2;
        f1 = f2;
        x2 = x3;
        count++;
        if (count < MAX)
            goto begin;
        else
            printf("The process doesn't converge.");
    }
    return 0;
}
