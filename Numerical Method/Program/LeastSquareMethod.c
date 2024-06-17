#include <stdio.h>

void linear_regression(int n, float x[], float y[], float *slope, float *intercept)
{
    float sum_x = 0, sum_y = 0, sum_xy = 0, sum_x_squared = 0;

    // Calculate required sums
    for (int i = 0; i < n; i++)
    {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x_squared += x[i] * x[i];
    }

    // Calculate slope (m) and intercept (c)
    *slope = (n * sum_xy - sum_x * sum_y) / (n * sum_x_squared - sum_x * sum_x);
    *intercept = (sum_y - *slope * sum_x) / n;
}

int main()
{
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    float x[n], y[n];
    printf("Enter the data points in the format (x y):\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%f %f", &x[i], &y[i]);
    }

    float slope, intercept;
    linear_regression(n, x, y, &slope, &intercept);

    printf("\nThe linear regression equation is: y = %.2fx + %.2f\n", slope, intercept);

    return 0;
}
