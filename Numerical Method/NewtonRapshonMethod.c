// 2. Write a program to find the root of non-linear equation using Newton Raphson method.
#include <stdio.h>
#include <conio.h>
#include <math.h>
#define MAX 20
#define E 0.0001
#define f(x) (x * x * x - 3 * x - 2)
#define f1(x) (3 * x * x - 3)
int main()
{
    int count = 1;
    float x0, x1;
    printf("\nEnter the initial guess value: ");
    scanf("%f", &x0);
    if (f1(x0) == 0)
        printf("Derivative is zero at guess value.");
    else
    {
    begin:
        x1 = x0 - (f(x0) / f1(x0));
        if (fabs((x1 - x0) / x1) < E)
        {
            printf("The root is %f", x1);
            printf("\nNo. of iterations is %d", count);
            printf("\n\n\n");
        }
        else
        {
            x0 = x1;
            count++;
            if (count < MAX)
                goto begin;
            else
                printf("The process doesn't converge.");
        }
    }
    return 0;
}
