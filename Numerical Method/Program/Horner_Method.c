#include <stdio.h>

float a[100], b[100];

int main()
{
    float x;
    int n, i;

    printf("Enter degree of polynomial: ");
    scanf("%d", &n);

    printf("Enter coefficients of dividend polynomial: \n");
    for (i = n; i >= 0; i--)
    { // Corrected the loop condition
        scanf("%f", &a[i]);
    }

    printf("Enter the value at which polynomial to be evaluated: ");
    scanf("%f", &x);

    b[n] = a[n];
    for (i = n - 1; i >= 0; i--)
    {                               // Changed loop condition and variable
        b[i] = a[i] + b[i + 1] * x; // Corrected Horner's method
    }

    printf("Value of polynomial p(%.3f) = %.3f\n", x, b[0]);

    return 0;
}
