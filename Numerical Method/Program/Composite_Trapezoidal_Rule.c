#include <stdio.h>
#include <math.h>

#define f(x) (pow(x, 3) + 1)

float composite_trapezoidal_rule(float a, float b, int n)
{
    float h = (b - a) / n;
    float sum = 0;

    // Calculate the sum of function values at intermediate points
    for (int i = 1; i < n; i++)
    {
        float xi = a + i * h;
        sum += f(xi);
    }

    // Apply the composite trapezoidal rule formula
    float integral = h * (f(a) + f(b) + 2 * sum) / 2;
    return integral;
}

int main()
{
    float a, b;
    int n;

    printf("Enter the initial value of x: ");
    scanf("%f", &a);
    printf("Enter the final value of x: ");
    scanf("%f", &b);
    printf("Enter the number of segments: ");
    scanf("%d", &n);

    float result = composite_trapezoidal_rule(a, b, n);
    printf("\nThe integration using Composite Trapezoidal Rule is approximately %.6f\n", result);

    return 0;
}
