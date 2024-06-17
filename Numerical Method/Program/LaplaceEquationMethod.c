#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
    int n, i, j, k;
    float sum, error, a[10][10], b[10], new_x[10], old_x[10], tl, tr, tb, tu, E[10];

    printf("Enter Dimension of plate: ");
    scanf("%d", &n);

    printf("Enter temperatures at left, right, bottom & upper part of plate:\n ");
    scanf("%f%f%f%f", &tl, &tr, &tb, &tu);

    // Construction of Coefficient matrix
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == j)
                a[i][j] = -4;
            else if (j == (n - i))
                a[i][j] = 0;
            else
                a[i][j] = 1;
        }
    }

    // Construction of RHS vector
    k = 0;
    for (i = 1; i < n; i++)
    {
        for (j = 1; j < n; j++)
        {
            if ((i - 1) == 0)
                b[k] = -tl;
            if ((i + 1) == n)
                b[k] = -tr;
            if ((j - 1) == 0)
                b[k] = -tb;
            if ((j + 1) == n)
                b[k] = -tu;
            k++;
        }
    }

    printf("Enter Accuracy Limit: ");
    scanf("%f", &error);

    // Initialize solution vector
    for (i = 0; i <= n; i++)
    {
        new_x[i] = 0;
    }

    // Solving system of linear equations by using Gauss-Seidel method with while loop
    int iteration = 0;
    while (1)
    {
        iteration++;

        // Copy current solution to old_x
        for (i = 0; i <= n; i++)
        {
            old_x[i] = new_x[i];
        }

        // Update each variable using Gauss-Seidel iteration
        for (i = 0; i <= n; i++)
        {
            sum = b[i];
            for (j = 0; j <= n; j++)
            {
                if (i != j)
                    sum -= a[i][j] * new_x[j];
            }
            new_x[i] = sum / a[i][i];
        }

        // Calculate the error for each variable
        for (i = 0; i <= n; i++)
        {
            sum = b[i];
            for (j = 0; j <= n; j++)
            {
                sum -= a[i][j] * new_x[j];
            }
            E[i] = fabs(new_x[i] - old_x[i]) / fabs(new_x[i]);
        }

        // Check termination condition
        int terminate = 1;
        for (i = 0; i <= n; i++)
        {
            if (E[i] > error)
            {

                break;
            }
        }

        if (i == (n + 1))
            break;
        else
            continue;
    }

    // Output the solution
    printf("Solution:\n");
    for (i = 0; i <= n; i++)
    {
        printf("x%d = %6.2f\n", i + 1, new_x[i]);
    }

    getch(); // To hold the console window open
    return 0;
}