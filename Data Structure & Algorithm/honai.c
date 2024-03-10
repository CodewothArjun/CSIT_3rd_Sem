#include <stdio.h>

int gameHonai(int n, char from, char temp, char to)
{
    if (n == 1)
    {
        printf("\nMove disk 1 from %c to %c ", from, to);
    }
    else if (n > 1)
    {
        gameHonai(n - 1, from, to, temp);
        printf("\nMove disk %d from %c to %c ", n, from, to);
        gameHonai(n - 1, temp, from, to);
    }
}

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Result of Honai Game");
    int Honai = gameHonai(n, 'A', 'B', 'C');
}