#include <stdio.h>

int main()
{
    int num = 550, arr[] = {1, 4, 11, 34, 44, 47, 50, 55, 65, 78, 90, 110};
    int arrLen, mid, low, high;
    arrLen = sizeof(arr) / sizeof(arr[0]);
    low = 0, high = arrLen - 1;
    mid = (low + high) / 2;
    while ((num != arr[mid]) && (low <= high))
    {
        if (num < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
        mid = (low + high) / 2;
    }
    if (arr[mid] == num)
    {
        printf("'%d' is found at position %d. ", num, mid);
    }
    else
    {
        printf("%d is not found.", num);
    }
    return 0;
}