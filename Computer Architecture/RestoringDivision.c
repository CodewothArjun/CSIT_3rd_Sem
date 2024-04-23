#include <stdio.h>
#include <math.h>

int a = 0, b = 0, c = 0, com[5] = {1, 0, 0, 0, 0}, s = 0;
int anum[5] = {0}, bnum[5] = {0}, anumcp[5] = {0};
int acomp[5] = {0}, bcomp[5] = {0}, rem[5] = {0}, quo[5] = {0}, res[5] = {0};

void binary()
{
    a = fabs(a);
    b = fabs(b);
    int r, r2, i, temp;

    for (i = 0; i < 5; i++)
    {
        r = a % 2;
        a = a / 2;
        r2 = b % 2;
        b = b / 2;
        anum[i] = r;
        anumcp[i] = r;
        bnum[i] = r2;

        if (r2 == 0)
            bcomp[i] = 1;
        if (r == 0)
            acomp[i] = 1;
    }
    c = 0;

    for (i = 0; i < 5; i++)
    {
        res[i] = com[i] + bcomp[i] + c;
        if (res[i] >= 2)
            c = 1;
        else
            c = 0;
        res[i] = res[i] % 2;
    }

    for (i = 4; i >= 0; i--)
        bcomp[i] = res[i];
}

void add(int num[])
{
    int i, c = 0;

    for (i = 0; i < 5; i++)
    {
        res[i] = rem[i] + num[i] + c;
        if (res[i] >= 2)
            c = 1;
        else
            c = 0;
        res[i] = res[i] % 2;
    }

    for (i = 4; i >= 0; i--)
    {
        rem[i] = res[i];
        printf("%d", rem[i]);
    }
    printf(" : ");

    for (i = 4; i >= 0; i--)
    {
        printf("%d", anumcp[i]);
    }
}

void shl()
{
    int i;
    for (i = 4; i > 0; i--)
        rem[i] = rem[i - 1];
    rem[0] = anumcp[4];

    for (i = 4; i > 0; i--)
        anumcp[i] = anumcp[i - 1];
    anumcp[0] = 0;
    printf("\nSHIFT LEFT: ");

    for (i = 4; i >= 0; i--)
        printf("%d", rem[i]);
    printf(" : ");

    for (i = 4; i >= 0; i--)
        printf("%d", anumcp[i]);
}

int main()
{
    int i;
    printf("RESTORING DIVISION\n\nEnter two numbers to divide\nBoth numbers should be less than 16\n\n");

    do
    {
        printf("Enter the dividend: ");
        scanf("%d", &a);
        printf("Enter the divisor: ");
        scanf("%d", &b);
    } while (a >= 16 || b >= 16);

    printf("\nExpected Quotient: %d\n", a / b);
    printf("Expected Remainder: %d\n", a % b);

    if (pow(a, b) < 0)
        s = 1;
    binary();

    printf("\n\nUnsigned Binary Equivalents are: \n");
    printf("A: ");
    for (i = 4; i >= 0; i--)
        printf("%d", anum[i]);

    printf("\nB: ");
    for (i = 4; i >= 0; i--)
        printf("%d", bnum[i]);

    printf("\nB'+1: ");
    for (i = 4; i >= 0; i--)
        printf("%d", bcomp[i]);

    printf("\n\n-->");
    shl();

    for (i = 0; i < 5; i++)
    {
        printf("\n-->");
        printf("\nSUB B: ");
        add(bcomp);

        if (rem[4] == 1)
        {
            printf("\n--> RESTORE\nADD B: ");
            anumcp[0] = 0;
            add(bnum);
        }
        else
        {
            anumcp[0] = 1;
        }
        if (i < 4)
        {
            shl();
        }
    }
    printf("\n----------------------------\n");
    printf("Sign of result: %d\n", s);
    printf("Remainder: ");
    for (i = 4; i >= 0; i--)
        printf("%d", rem[i]);
    printf("\nQuotient: ");
    for (i = 4; i >= 0; i--)
        printf("%d", anumcp[i]);

    return 0;
}
