/*
Write a program to enter n numbers and sort according to
a) Bubble sort
b) Insertion sort
c) Selection sort
d) Quick sort
e) Merge sort
f) Heap sort
*/

#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Insertion Sort
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Selection Sort
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

// Quick Sort
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Merge Sort
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Heap Sort
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

// Function to print an array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d numbers: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Bubble Sort
    int arr_bubble[n];
    for (int i = 0; i < n; i++)
    {
        arr_bubble[i] = arr[i];
    }
    bubbleSort(arr_bubble, n);
    printf("Sorted array using Bubble Sort: ");
    printArray(arr_bubble, n);

    // Insertion Sort
    int arr_insertion[n];
    for (int i = 0; i < n; i++)
    {
        arr_insertion[i] = arr[i];
    }
    insertionSort(arr_insertion, n);
    printf("Sorted array using Insertion Sort: ");
    printArray(arr_insertion, n);

    // Selection Sort
    int arr_selection[n];
    for (int i = 0; i < n; i++)
    {
        arr_selection[i] = arr[i];
    }
    selectionSort(arr_selection, n);
    printf("Sorted array using Selection Sort: ");
    printArray(arr_selection, n);

    // Quick Sort
    int arr_quick[n];
    for (int i = 0; i < n; i++)
    {
        arr_quick[i] = arr[i];
    }
    quickSort(arr_quick, 0, n - 1);
    printf("Sorted array using Quick Sort: ");
    printArray(arr_quick, n);

    // Merge Sort
    int arr_merge[n];
    for (int i = 0; i < n; i++)
    {
        arr_merge[i] = arr[i];
    }
    mergeSort(arr_merge, 0, n - 1);
    printf("Sorted array using Merge Sort: ");
    printArray(arr_merge, n);

    // Heap Sort
    int arr_heap[n];
    for (int i = 0; i < n; i++)
    {
        arr_heap[i] = arr[i];
    }
    heapSort(arr_heap, n);
    printf("Sorted array using Heap Sort: ");
    printArray(arr_heap, n);

    return 0;
}
