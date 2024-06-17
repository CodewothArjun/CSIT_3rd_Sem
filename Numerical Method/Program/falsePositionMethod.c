
#include <stdio.h>
#include <math.h>

#define MAX 20
#define E 0.0001

float g(float x)
{
    return exp(x) - 2; 
}

int main()
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
        printf("The root is %f\n", x1);
        printf("No. of iterations: %d\n", count);
    }
    else
    {
        x0 = x1;
        count++;

        if (count < MAX)
        {
            goto begin;
        }
        else
        {
            printf("The process doesn't converge.\n");
        }
    }
    printf("\n\n");
    return 0;
}
