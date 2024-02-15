#include "bubble_sort.h"

#include <stdio.h>

namespace bubble_sort
{
    // Swap function
    void swap(int *arr, int i, int j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // A function to implement bubble sort
    void bubbleSort(int arr[], int n)
    {
        int i, j;
        for (i = 0; i < n - 1; i++)

            // Last i elements are already
            // in place
            for (j = 0; j < n - i - 1; j++)
                if (arr[j] > arr[j + 1])
                    swap(arr, j, j + 1);
    }

    // Function to print an array
    void printArray(int arr[], int size)
    {
        int i;
        for (i = 0; i < size; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }

    int main()
    {
        int arr[] = {7, 6, 5, 4, 3};
        int N = sizeof(arr) / sizeof(int);
        bubbleSort(arr, N);
        printf("Sorted array: ");
        printArray(arr, N);
        return 0;
    }
}