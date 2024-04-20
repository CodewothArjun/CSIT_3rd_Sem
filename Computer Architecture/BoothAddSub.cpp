#include <iostream>
using namespace std;

// Function to compute Booth's multiplication
int boothMultiplication(int a, int b)
{
    int result = 0;
    int ac = 0; // Accumulator

    while (b != 0)
    {
        if (b & 1)
        {
            result += a;        // Add multiplicand to result
            ac = (ac + a) >> 1; // Arithmetic shift right
        }
        else
        {
            ac >>= 1; // Only shift accumulator
        }
        a <<= 1; // Shift multiplicand left
        b >>= 1; // Shift multiplier right
    }
    return result;
}

int main()
{
    int multiplicand = 12; // Example: 12
    int multiplier = -7;   // Example: -7

    int product = boothMultiplication(multiplicand, multiplier);
    cout << "Product: " << product << endl;

    return 0;
}
