#include <stdio.h>
#include "util.h"

// function prototypes
void mergeSort(int *arr, int start, int end);
void merge(int *arr, int start, int midpoint, int end);

int main()
{

    int size = sizeof(randomArray) / sizeof(randomArray[0]);

    printArr(randomArray, size);
    // call for merge
    mergeSort(randomArray, 0, size - 1);
    printArr(randomArray, size);
}

void mergeSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int midpoint = start + (end - start) / 2;
        // sort left
        mergeSort(arr, start, midpoint);
        // sort right
        mergeSort(arr, midpoint + 1, end);
        // merge
        merge(arr, start, midpoint, end);
    }
}

void merge(int arr[], int start, int midpoint, int end)
{
    // indexes
    int i, j, k;

    // size of new arrays
    int sizeOfFirstArray = (midpoint - start) + 1;

    int sizeOfSecArray = (end - midpoint);

    int firstArray[sizeOfFirstArray];
    int secondArray[sizeOfSecArray];

    for (i = 0; i < sizeOfFirstArray; i++)
    {
        firstArray[i] = arr[start + i];
    }

    for (j = 0; j < sizeOfSecArray; j++)
    {
        secondArray[j] = arr[midpoint + j + 1];
    }

    i = j = 0;

    k = start;

    while (i < sizeOfFirstArray && j < sizeOfSecArray)
    {
        if (firstArray[i] <= secondArray[j])
        {
            arr[k] = firstArray[i];
            i++;
        }
        else
        {
            arr[k] = secondArray[j];
            j++;
        }
        k++;
    }

    // handle single cases
    while (i < sizeOfFirstArray)
    {
        arr[k] = firstArray[i];
        i++;
        k++;
    }

    while (j < sizeOfSecArray)
    {
        arr[k] = secondArray[j];
        j++;
        k++;
    }
}