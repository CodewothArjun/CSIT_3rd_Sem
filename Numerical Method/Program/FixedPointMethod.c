// 4. Write a program to find the root of the non-linear equation using Fixed Point method.

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <conio.h>
#define MAX 30
#define E 0.0001
#define g(x) ((x * x + 8) / 6)

void main()
{
    int count = 1;
    float x0, x1, error;
    printf("Enter the initial guess value: ");
    scanf("%f", &x0);
begin:
    x1 = g(x0);
    error = x1 - x0;
    if (fabs(error) < E)
    {
        printf("The root is %f", x1);
        printf("\nNo. of iterations is %d", count);
        printf("\n\n");
    }
    else
    {
        x0 = x1;
        count++;
        if (count < MAX)
            goto begin;
        else
            printf("The process doesn\'t converge.");
    }
    getch();
}
