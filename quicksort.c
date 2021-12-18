#include <stdio.h>
#include "util.h"

void quickSort(int arr[], int start, int end);
int partition(int arr[], int start, int end);

int main()
{
    int size = sizeof(randomArray) / sizeof(randomArray[0]);
    printArr(randomArray, size);

    printf("the array size is %d\n", size);

    quickSort(randomArray, 0, size - 1);

    printArr(randomArray, size);
}

void quickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int pivot = partition(arr, start, end);

        // sort left
        quickSort(arr, start, pivot);
        // sort right
        quickSort(arr, pivot + 1, end);
    }
}

int partition(int arr[], int start, int end)
{
    int i = start;
    int j = end;

    int pivot = arr[i];

    while (i < j)
    {
        while (arr[i] < pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            // swap
            int temp = arr[j];

            arr[j] = arr[i];

            arr[i] = temp;
        }
    }
    return j;
}