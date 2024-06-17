// Write a program to implement binary search.
#include <stdio.h>
// Function to perform binary search
int binarySearch(int arr[], int low, int high, int key)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
        {
            return mid; // Return the index if found
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1; // Return -1 if not found
}

int main()
{
    int arr[] = {12, 23, 34, 45, 56, 78, 89};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key, result;
    printf("Arry List: 12, 23, 34, 45, 56, 78, 89 ");
    printf("\nEnter the element to search: ");
    scanf("%d", &key);

    result = binarySearch(arr, 0, n - 1, key);

    if (result != -1)
    {
        printf("Element found at index %d\n", result);
    }
    else
    {
        printf("Element not found in the array\n");
    }

    return 0;
}
