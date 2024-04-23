#include <stdio.h>

// Function to perform signed 2's complement addition
int signedAddition(int x, int y)
{
    int carry = 0;
    while (y != 0)
    {
        // Calculate carry
        carry = x & y;

        // Perform addition without carry
        x = x ^ y;

        // Calculate carry for the next iteration
        y = carry << 1;
    }
    return x;
}

// Function to perform signed 2's complement subtraction
int signedSubtraction(int x, int y)
{
    // Convert y to its 2's complement
    y = signedAddition(~y, 1);

    // Perform addition of x and -y (which is equivalent to subtraction)
    return signedAddition(x, y);
}

// Function to perform Booth addition of signed 2's complement data
int boothAddition(int x, int y)
{
    int sum = 0;
    int carry = 0;

    while (y != 0)
    {
        // Calculate sum without carry
        sum = x ^ y;

        // Calculate carry
        carry = x & y;

        // Perform left shift by 1
        carry = carry << 1;

        // Update x and y for the next iteration
        x = sum;
        y = carry;
    }

    return sum;
}

// Function to perform Booth subtraction of signed 2's complement data
int boothSubtraction(int x, int y)
{
    // Convert y to its 2's complement
    y = signedAddition(~y, 1);

    // Perform Booth addition of x and -y (which is equivalent to subtraction)
    return boothAddition(x, y);
}

int main()
{
    int x, y;
    printf("Enter the first operand (x): ");
    scanf("%d", &x);
    printf("Enter the second operand (y): ");
    scanf("%d", &y);

    // Perform signed 2's complement addition
    int additionResult = signedAddition(x, y);
    printf("Result of signed addition: %d\n", additionResult);

    // Perform signed 2's complement subtraction
    int subtractionResult = signedSubtraction(x, y);
    printf("Result of signed subtraction: %d\n", subtractionResult);

    // Perform Booth addition
    int boothAddResult = boothAddition(x, y);
    printf("Result of Booth addition: %d\n", boothAddResult);

    // Perform Booth subtraction
    int boothSubResult = boothSubtraction(x, y);
    printf("Result of Booth subtraction: %d\n", boothSubResult);
    return 0;
}
