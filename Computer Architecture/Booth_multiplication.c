#include <stdio.h>

void add(int ac[], int x[], int qrn)
{
    int i, c = 0;
    for (i = 0; i < qrn; i++)
    {
        ac[i] = ac[i] + x[i] + c;
        if (ac[i] > 1)
        {
            ac[i] = ac[i] % 2;
            c = 1;
        }
        else
            c = 0;
    }
}

void complement(int a[], int n)
{
    int i;
    int x[8] = {0};
    x[0] = 1;
    for (i = 0; i < n; i++)
    {
        a[i] = (a[i] + 1) % 2;
    }
    add(a, x, n);
}

void rightShift(int ac[], int qr[], int *qn, int qrn)
{
    int temp, i;
    temp = ac[0];
    *qn = qr[0];
    printf("\t\trightShift\t");
    for (i = 0; i < qrn - 1; i++)
    {
        ac[i] = ac[i + 1];
        qr[i] = qr[i + 1];
    }
    qr[qrn - 1] = temp;
}

void display(int ac[], int qr[], int qrn)
{
    int i;
    for (i = qrn - 1; i >= 0; i--)
        printf("%d", ac[i]);
    printf("\t");
    for (i = qrn - 1; i >= 0; i--)
        printf("%d", qr[i]);
}

void boothAlgorithm(int br[], int qr[], int mt[], int qrn, int sc)
{
    int qn = 0, ac[10] = {0};
    int temp = 0;
    printf("qn\tq[n+1]\t\tBR\t\tAC\tQR\t\tsc\n");
    printf("\t\t\tinitial\t\t");
    display(ac, qr, qrn);
    printf("\t\t%d\n", sc);

    while (sc != 0)
    {
        printf("%d\t%d", qr[0], qn);
        if ((qn + qr[0]) == 1)
        {
            if (temp == 0)
            {
                add(ac, mt, qrn);
                printf("\t\tA = A - BR\t");
                display(ac, qr, qrn);
                temp = 1;
            }
            else if (temp == 1)
            {
                add(ac, br, qrn);
                printf("\t\tA = A + BR\t");
                display(ac, qr, qrn);
                temp = 0;
            }
            printf("\n\t");
            rightShift(ac, qr, &qn, qrn);
        }
        else if (qn - qr[0] == 0)
            rightShift(ac, qr, &qn, qrn);
        display(ac, qr, qrn);
        printf("\t");
        sc--;
        printf("\t%d\n", sc);
    }
}

int main()
{
    int mt[10], sc;
    int brn, qrn;
    brn = 4;
    int br[] = {0, 1, 1, 0};

    for (int i = brn - 1; i >= 0; i--)
        mt[i] = br[i];

    // Reversing the bits in mt to find the two's complement
    for (int i = 0; i < brn; i++)
        mt[i] = 1 - mt[i];

    complement(mt, brn);

    qrn = 4;
    sc = qrn;
    int qr[] = {1, 0, 1, 0};

    boothAlgorithm(br, qr, mt, qrn, sc);

    printf("\nResult = ");
    for (int i = qrn - 1; i >= 0; i--)
        printf("%d", qr[i]);

    return 0;
}
