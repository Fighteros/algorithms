#include <iostream>


using namespace std;

// function prototypes
void selectionSort(int arr[], int arraySize);
void printArray(int arr[], int arraySize);
void bubbleSort(int arr[], int arraySize);
void mergeSort(int arr[], int start, int end);
void merge(int arr[], int start, int midpoint, int end);
void insertionSort(int arr[], int size);
void quickSort(int arr[], int start, int end);
int partition(int arr[], int start, int end);


int main(void)
{
	int arr[] = { 10, 7, 3, 8, 12, 4, 2, 1 };
	int arr_sorted[] = { 1, 2, 3, 4, 7, 8, 10, 12 };
	int arraySize = sizeof(arr) / sizeof(arr[0]); // length of array / length of one item

	printArray(arr, arraySize);
	cout << endl;
	//selectionSort(arr, arraySize);
	//bubbleSort(arr, arraySize);
	//bubbleSort(arr_sorted, arraySize);

	//mergeSort(arr, 0, arraySize - 1);

	//insertionSort(arr, arraySize);

	quickSort(arr, 0, arraySize - 1);

	printArray(arr, arraySize);
}

/* quick sort */
void quickSort(int arr[], int start, int end)
{
	if (start < end)
	{
		int pivot = partition(arr,start, end);
		cout << pivot << endl;

		quickSort(arr, start, pivot);
		quickSort(arr, pivot + 1, end);
	}
}

 
int partition(int arr[], int start, int end)
{
	int i = start;
	int j = end;

	int pivot = arr[start];

	while(i < j)
	{
		while (arr[i] < pivot){
			i++;
		}

		while (arr[j] > pivot)
		{
			j--;
		}
	

		if (i < j)
		{
			// swap elements
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	return j;
}



/* end quick sort */


/* insertion sort - good with linked list */
// 80 90 60 40 50 70 30
void insertionSort(int arr[], int size)
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
/* insertion sort  */

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
	int count = 0;
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
				count++;
				isSorted = false;
			}
		}
		if (isSorted)
		{
			cout << "array is sorted!" << endl;
			break;
		}
	}

	cout << count << " this was count"<<endl;
}


/* Merge sort */

// to get the mid point in subarrays so that we divide it
//midPoint = start + (end - start) / 2
void mergeSort(int arr[], int start, int end)
{
	if (start < end)
	{
		int midpoint = start + (end - start) / 2;
		mergeSort(arr, start, midpoint);
		mergeSort(arr, midpoint + 1, end);
		merge(arr, start, midpoint, end);
	}
}

void merge(int arr[], int start, int midpoint, int end)
{
	/* indexs */
	int i, j, k;
	// split into two arrays
	// addes on to left always so if the length of the Array is odd it works for us
	int sizeOfFirstArray = midpoint - start + 1;
	int sizeOfSecArray = end - midpoint;

	// create new two sub-arrays pointers
	int* firstArray = new int[sizeOfFirstArray];
	int* secondArray = new int[sizeOfSecArray];

	for (i = 0; i < sizeOfFirstArray; i++)
	{
		firstArray[i] = arr[start + i];
	}
	// notice that the fisrt array is filled from zero to 3 
	for (j = 0; j < sizeOfSecArray; j++) 
	{
		secondArray[j] = arr[midpoint + 1 +j];
	}

	i = j = 0;
	k = start;

	while (i < sizeOfFirstArray && j < sizeOfSecArray)
	{
		// compare starting of sub-arrays
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
	// if a sub-array finished before the other fill the left elements into the sorted array

	while (i < sizeOfFirstArray)
	{
		arr[k] = firstArray[i];
		i++;
		k++;
	}

	while (i < sizeOfSecArray)
	{
		arr[k] = secondArray[j];
		j++;
		k++;
	}
}

/* end Merge Sort */

//print array
void printArray(int arr[], int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << arr[i] << " ";
	}
}