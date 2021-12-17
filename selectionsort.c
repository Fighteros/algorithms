#include <stdio.h>
// function prototypes

void sort(int *arr, int size);
void printArr(int *arr, int size);

int main()
{
    int arr[] = {10, 9, 5, 2, 1};
    // get array_size
    int size = sizeof(arr) / sizeof(arr[0]);
    printArr(arr, size);
    // @TODO Sort it by selection sort
    sort(arr, size);
    printArr(arr, size);
}

// sort the array
void sort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minNumberIndex = i;
        for (int j = 0 + i; j < size; j++)
        {
            if (arr[j] < arr[minNumberIndex])
            {
                minNumberIndex = j;
            }
        }

        // swap the smallest number with the first unsorted item
        int temp = arr[minNumberIndex];
        arr[minNumberIndex] = arr[i];
        arr[i] = temp;
    }
}

// helper function to print the array
void printArr(int *arr, int size)
{
    printf("[ ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}
