#include <stdio.h>
#include <graphics.h>

void liangBarsky(int x1, int y1, int x2, int y2, int xmin, int ymin, int xmax, int ymax) {
    float t1 = 0, t2 = 1;
    int dx = x2 - x1, dy = y2 - y1;
    int p[4] = {-dx, dx, -dy, dy};
    int q[4] = {x1 - xmin, xmax - x1, y1 - ymin, ymax - y1};

    for (int i = 0; i < 4; i++) {
        if (p[i] == 0 && q[i] < 0) {
            printf("Line is parallel to clipping window and outside of it\n");
            return;
        }
        float t = (float)q[i] / p[i];
        if (p[i] < 0) {
            if (t > t1) t1 = t;
        } else if (p[i] > 0) {
            if (t < t2) t2 = t;
        }
    }

    if (t1 < t2) {
        int x1_new = x1 + t1 * dx;
        int y1_new = y1 + t1 * dy;
        int x2_new = x1 + t2 * dx;
        int y2_new = y1 + t2 * dy;

        setcolor(WHITE);
        line(x1_new, y1_new, x2_new, y2_new);
    } else {
        printf("Line lies completely outside the clipping window\n");
    }
}

int main() {
    printf("\nBabu Jaldabir Dangol\n");
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Clipping window coordinates
    int xmin = 50, ymin = 50, xmax = 200, ymax = 200;
    rectangle(xmin, ymin, xmax, ymax);

    // Line coordinatess
    int x1, y1, x2, y2;
    printf("Enter the coordinates of the line (x1 y1 x2 y2): ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    setcolor(YELLOW);
    line(x1, y1, x2, y2);

    liangBarsky(x1, y1, x2, y2, xmin, ymin, xmax, ymax);

    getch();
    closegraph();

    return 0;
}
