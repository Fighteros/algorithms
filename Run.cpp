#include <iostream>


using namespace std;

// function prototypes
void selectionSort(int arr[], int arraySize);
void printArray(int arr[], int arraySize);
void bubbleSort(int arr[], int arraySize);

int main(void)
{
	int arr[] = { 10, 7, 3, 8, 12, 4, 2, 1 };
	int arr_sorted[] = { 1, 2, 3, 4, 7, 8, 10, 12 };
	int arraySize = sizeof(arr) / sizeof(arr[0]); // length of array / length of one item

	printArray(arr_sorted, arraySize);
	cout << endl;
	//selectionSort(arr, arraySize);
	//bubbleSort(arr, arraySize);
	bubbleSort(arr_sorted, arraySize);

	printArray(arr_sorted, arraySize);
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
// bubble sort
void bubbleSort(int arr[], int arraySize)
{
	// assume best case scenario 
	bool isSorted = true;
	for (int i = 0; i < arraySize - 1; i++)
	{
		for (int j = 0; j < arraySize - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				// built in function in c++
				//swap(arr[j], arr[j + 1]);
				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;

				isSorted = false;
			}
		}
		if (isSorted)
		{
			cout << "array is sorted!" << endl;
			break;
		}
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