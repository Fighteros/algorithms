#include <stdio.h>
#include "util.h"

// function prototypes
void insetionSort(int arr[], int size);

int main()
{
    int size = sizeof(randomArray) / sizeof(randomArray[0]);

    printArr(randomArray, size);

    insetionSort(randomArray, size);

    printArr(randomArray, size);
}

void insetionSort(int arr[], int size)
{
    int key, j;

    for (int i = 1; i < size; i++)
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