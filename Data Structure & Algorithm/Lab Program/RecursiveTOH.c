// Write a recursive program to implement TOH problem.

#include <stdio.h>

// Recursive function to solve Tower of Hanoi problem
void towerOfHanoi(int n, char source, char temp, char destination)
{
    if (n == 1)
    {
        printf("Move disk %d from %c to %c\n", n, source, destination);
        return;
    }
    towerOfHanoi(n - 1, source, destination, temp);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    towerOfHanoi(n - 1, temp, source, destination);
}

int main()
{
    int num_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);
    printf("Tower of Hanoi solution for %d disks:\n", num_disks);
    towerOfHanoi(num_disks, 'A', 'B', 'C');
    printf("\n\n");
    return 0;
}
