#include <iostream>


using namespace std;

// function prototypes
void selectionSort(int arr[], int arraySize);
void printArray(int arr[], int arraySize);

int main(void)
{
	int arr[] = { 10, 7, 3, 8, 12, 4, 2, 1 };
	int arraySize = sizeof(arr) / sizeof(arr[0]); // length of array / length of one item

	printArray(arr, arraySize);
	cout << endl;
	selectionSort(arr, arraySize);

	printArray(arr, arraySize);
}

// selection sort
void selectionSort(int arr[], int arraySize)
{
	for (int i = 0; i < arraySize - 1; i++)
	{
		int minNumIndex = i;
		for (int j = i + 1; j < arraySize; j++)
		{
			if (arr[j] < arr[minNumIndex])
			{
				minNumIndex = j;
			}
		}

		int temp = arr[minNumIndex];
		arr[minNumIndex] = arr[i];
		arr[i] = temp;
	}
}

//print array
void printArray(int arr[], int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << arr[i] << " ";
	}
}