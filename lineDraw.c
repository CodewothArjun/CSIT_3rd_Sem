#include <stdio.h>
#include <math.h>

// Function to draw a line using Bresenham's algorithm
void drawLine(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int x, y;
    int p = 2 * dy - dx;

    // Start drawing from the first point
    x = x1;
    y = y1;

    // Draw the first point
    printf("(%d, %d)\n", x, y);

    // Iterate through the line
    while (x < x2)
    {
        x++;
        if (p < 0)
        {
            p += 2 * dy;
        }
        else
        {
            y++;
            p += 2 * (dy - dx);
        }
        // Draw the next point
        printf("(%d, %d)\n", x, y);
    }
}

int main()
{
    // Coordinates of the line segment
    int x1 = 10, y1 = 20;
    int x2 = 8, y2 = 30;

    // Draw the line using Bresenham's algorithm
    drawLine(x1, y1, x2, y2);

    return 0;
}
