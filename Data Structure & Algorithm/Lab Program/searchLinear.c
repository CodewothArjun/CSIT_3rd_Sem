// Write a program to implement linear search.

#include <stdio.h>
// Function to perform linear search
int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

int main()
{
    int arr[] = {12, 45, 78, 23, 56, 34, 89};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key, result;
    printf("Array List:\n12, 45, 78, 23, 56, 34, 89");

    printf("\nEnter the element to search: ");
    scanf("%d", &key);

    result = linearSearch(arr, n, key);

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
