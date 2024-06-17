////#include <stdio.h>
////#include <graphics.h>
////
////void liangBarsky(int x1, int y1, int x2, int y2, int xmin, int ymin, int xmax, int ymax) {
////    float t1 = 0, t2 = 1;
////    int dx = x2 - x1, dy = y2 - y1;
////    int p[4] = {-dx, dx, -dy, dy};
////    int q[4] = {x1 - xmin, xmax - x1, y1 - ymin, ymax - y1};
////
////    for (int i = 0; i < 4; i++) {
////        if (p[i] == 0 && q[i] < 0) {
////            printf("Line is parallel to clipping window and outside of it\n");
////            return;
////        }
////        float t = (float)q[i] / p[i];
////        if (p[i] < 0) {
////            if (t > t1) t1 = t;
////        } else if (p[i] > 0) {
////            if (t < t2) t2 = t;
////        }
////    }
////
////    if (t1 < t2) {
////        int x1_new = x1 + t1 * dx;
////        int y1_new = y1 + t1 * dy;
////        int x2_new = x1 + t2 * dx;
////        int y2_new = y1 + t2 * dy;
////
////        setcolor(WHITE);
////        line(x1_new, y1_new, x2_new, y2_new);
////    } else {
////        printf("Line lies completely outside the clipping window\n");
////    }
////}
////
////int main() {
////    
////    int gd = DETECT, gm;
////    initgraph(&gd, &gm, NULL);
////
////    // Clipping window coordinates
////    int xmin = 50, ymin = 50, xmax = 200, ymax = 200;
////    rectangle(xmin, ymin, xmax, ymax);
////
////    // Line coordinatess
////    int x1, y1, x2, y2;
////    printf("Enter the coordinates of the line (x1 y1 x2 y2): ");
////    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
////
////    setcolor(YELLOW);
////    line(x1, y1, x2, y2);
////
////    liangBarsky(x1, y1, x2, y2, xmin, ymin, xmax, ymax);
////
////    getch();
////    closegraph();
////
////    return 0;
////}
//
//
//
//#include <iostream>
//#include <math.h>
//#include <graphics.h>
// 
//using namespace std;
// 
//int main()
//{
//
//    int x[4],y[4],i;
//    double put_x,put_y,t;
// 
//int gr=DETECT,gm;
//initgraph (&gr,&gm,(char*)"");
//
//printf("Enter x and y coordinate:\n");
//
//for (i=0;i<4;i++)
//{
//scanf("%d%d",&x[i],&y[i]);
//
//}
//for (i=0;i<3;i++)
//{
//line (x[i],y[i],x[i+1],y[i+1]);
//}
//
//for (t=0.0;t<=1.0;t=t+0.001)
//{
//put_x=pow(1-t,3)*x[0]+3*t*pow(1-t,2)*x[1]+3*t*t*(1-t)*x[2]+pow(t,3)*x[3];
//put_y=pow(1-t,3)*y[0]+3*t*pow(1-t,2)*y[1]+3*t*t*(1-t)*y[2]+pow(t,3)*y[3];
//putpixel(put_x,put_y,WHITE);
//} 
//printf("\nBAbu Jaldabir Dangol\n");
//    getch();
//    closegraph();
// 
//}

#include <stdio.h>
#include <conio.h>
#include <graphics.h>
int main() {
    int rcode_begin[4] = {0, 0, 0, 0};
    int rcode_end[4] = {0, 0, 0, 0};
    int nmax, ymax, nmin, ymin, flag = 0;
    printf("bijay dhakal\n");
    float slope;
    int n, y, nt, yl, inc, ye;
    int gr = DETECT, gm;
    initgraph(&gr, &gm, "");
  printf("Enter nmin, ymin: ");
    scanf("%d %d", &nmin, &ymin);
    printf("Enter nmax, ymax: ");
    scanf("%d %d", &nmax, &ymax);
    printf("Enter initial point n and y: ");
    scanf("%d %d", &n, &y);
    printf("Enter final point nt and yl: ");
    scanf("%d %d", &nt, &yl);
    cleardevice();
    rectangle(nmin, ymin, nmax, ymax);
    line(n, y, nt, yl);
    line(10, 0, 600, 0);
    line(10, 0, 0, 600);
    if (y > ymax) {
        rcode_begin[0] = 1;
        flag = 1;
    } else if (y < ymin) {
        rcode_begin[1] = 1;
        flag = 1;
    }
    if (n > nmax) {
        rcode_begin[2] = 1;
        flag = 1;
    } else if (n < nmin) {
        rcode_begin[3] = 1;
        flag = 1;
    }
    if (yl > ymax) {
        rcode_end[0] = 1;
        flag = 1;
    } else if (yl < ymin) {
        rcode_end[1] = 1;
        flag = 1;
    }
    if (nt > nmax) {
        rcode_end[2] = 1;
        flag = 1;
    } else if (nt < nmin) {
        rcode_end[3] = 1;
        flag = 1;
    }

    if (flag == 0) {
        printf("No need to clip as it is already in the window\n");
    } else {
        slope = (float)(yl - y) / (nt - n);

        if (rcode_begin[2] == 0 && rcode_begin[3] == 0) {
            y = y + (nmin - n) * slope;
            n = nmin;
        }

        if (rcode_begin[2] == 1 && rcode_begin[3] == 0) {
            y = y + (nmax - n) * slope;
            n = nmax;
        }

        if (rcode_begin[0] == 1 && rcode_begin[1] == 0) {
            n = n + (ymin - y) / slope;
            y = ymin;
        }

        if (rcode_begin[0] == 0 && rcode_begin[1] == 1) {
            n = n + (ymax - y) / slope;
            y = ymax;
        }
        if (rcode_end[2] == 0 && rcode_end[3] == 1) {
            yl = yl + (nmin - nt) * slope;
            nt = nmin;
        }
        if (rcode_end[2] == 1 && rcode_end[3] == 0) {
            yl = yl + (nmax - nt) * slope;
            nt = nmax;
        }
        if (rcode_end[0] == 1 && rcode_end[1] == 0) {
            nt = nt + (ymin - yl) / slope;
            yl = ymin;
        }
        if (rcode_end[0] == 0 && rcode_end[1] == 1) {
            nt = nt + (ymax - yl) / slope;
            yl = ymax;
        }
    }
    delay(17000);
    clearviewport();
    rectangle(nmin, ymin, nmax, ymax);
    line(10, 0, 600, 0);
    line(0, 0, 0, 600);
    setcolor(RED);
    line(n, y, nt, yl);
    getch();
    closegraph();
}

