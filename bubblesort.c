#include <stdio.h>
#include "util.h"
#include <stdbool.h>
// function prototypes
void bubbleSort(int *arr, int size);

int main()
{
    int arr[] = {10, 9, 5, 2, 1};
    int arr_sorted[] = {1, 2, 5, 9, 10};
    // get array_size
    int size = sizeof(arr) / sizeof(arr[0]);
    printArr(arr_sorted, size);
    // @TODO Sort it by bubble sort
    bubbleSort(arr_sorted, size);
    printArr(arr_sorted, size);
}

void bubbleSort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        bool isSorted = true;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                isSorted = false;
            }

            if (isSorted == true)
            {
                printf("sorted array break now!\n");
                return;
            }
        }
    }
}