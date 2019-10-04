#include <stdlib.h>
#include <time.h>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 1000000;

// Set this to true if you wish the arrays to be printed.
const bool OUTPUT_DATA = false;


void ReadInput(string& sortAlg, int& size);

void GenerateSortedData(int data[], int size);
void GenerateReverselySortedData(int data[], int size);
void GenerateRandomData(int data[], int size);
void GenerateNearlySortedData(int data[], int size);

void Sort(int data[], int size, string sortAlg, char* dataType);

void SelectionSort(int data[], int size);
void BubbleSort(int data[], int size);
void InsertionSort(int data[], int size);
void SelectionSort2(int data[], int size);

void Swap(int &x, int &y);

bool IsSorted(int data[], int size);
void printData(int data[], int size, string title);


int main(void)
{
	int size;
	string sortAlg;
	ReadInput(sortAlg, size);

	int * data = new int[size];

	GenerateSortedData(data, size);
	Sort(data, size, sortAlg, "Sorted Data:");

	GenerateReverselySortedData(data, size);
	Sort(data, size, sortAlg, "Reversely Sorted Data");

	GenerateRandomData(data, size);
	Sort(data, size, sortAlg, "Random Data");

	GenerateNearlySortedData(data, size);
	Sort(data, size, sortAlg, "Nearly Sorted Data");

	cout << "\nProgram Completed Successfully." << endl;;

	return 0;
}
/********************************************************************/




// This function asks the user to choose the sorting algorithm and the array size
void ReadInput(string& sortAlg, int& size)
{
	cout << "  I:\tInsertion Sort" << endl;
	cout << "  S:\tSelection Sort" << endl;
	cout << "  B:\tBubble Sort" << endl;
	cout << "  2:\tSelection Sort 2" << endl;
	cout << "Enter sorting algorithm: ";
	cin >> sortAlg;
	string sortAlgName;


	if (sortAlg == "S")
		sortAlgName = "Selection Sort";
	else if (sortAlg == "B")
		sortAlgName = "Bubble Sort";
	else if (sortAlg == "I")
		sortAlgName = "Insertion Sort";
	else if (sortAlg == "2")
		sortAlgName = "Selection Sort 2";
	else {
		cout << "\nUnrecognized sorting algorithm Code: " << sortAlg << endl;
		exit(1);
	}


	cout << "Enter input size: ";
	cin >> size;

	if (size < 1 || size > MAX_SIZE)
	{
		cout << "\nInvalid input size " << size
			<< ". Size should be between 1 and " << MAX_SIZE << endl;
		exit(1);
	}

	cout << "\nSorting Algorithm: " << sortAlgName;
	cout << "\nInput Size = " << size << endl;
	cout << endl;

}
/******************************************************************************/




void GenerateSortedData(int data[], int size)
{
	int i;

	for (i = 0; i < size; i++)
		data[i] = i * 3 + 5;
}

/*****************************************************************************/




void GenerateReverselySortedData(int data[], int size)
{
	int i;

	for (i = 0; i < size; i++)
		data[i] = (size - i) * 2 + 3;

}
/*****************************************************************************/




void GenerateRandomData(int data[], int size)
{
	int i;

	for (i = 0; i < size; i++)
		data[i] = rand();
}
/*****************************************************************************/




void GenerateNearlySortedData(int data[], int size)
{
	int i;

	GenerateSortedData(data, size);

	for (i = 0; i<size; i++)
		if (i % 10 == 0)
			if (i + 1 < size)
				data[i] = data[i + 1] + 9;
}
/*****************************************************************************/



// This function performs sorting depending on the algorithm chosen by the user.
void Sort(int data[], int size, string sortAlg, char* dataType)
{

	cout << endl << dataType << ":";


	if (OUTPUT_DATA)
		printData(data, size, "Data before sorting:");



	// Sorting is about to begin ... start the timer!
	clock_t start = clock();


	if (sortAlg == "S")
		SelectionSort(data, size);
	else if (sortAlg == "B")
		BubbleSort(data, size);
	else if (sortAlg == "I")
		InsertionSort(data, size);
	else if (sortAlg == "2")
		SelectionSort2(data, size);
	else
	{
		cout << "Invalid sorting algorithm!" << endl;
		exit(1);
	}

	// Sorting has finished ... stop the timer!
	clock_t end = clock();
	double elapsed = (((double)(end - start)) / CLOCKS_PER_SEC) * 1000;



	if (OUTPUT_DATA)
		printData(data, size, "Data after sorting:");


	if (IsSorted(data, size))
		cout << "\nCorrectly sorted " << size << " elements in " << elapsed << "ms";
	else
		cout << "ERROR!: INCORRECT SORTING!" << endl;
	cout << "\n-------------------------------------------------------------\n";
}
/*****************************************************************************/




bool IsSorted(int data[], int size)
{
	int i;

	for (i = 0; i<(size - 1); i++)
	{
		if (data[i + 1] < data[i])
			return false;
	}
	return true;
}
/*****************************************************************************/




void SelectionSort(int data[], int n)
{
	// write your code here
	int min;
	for (int i = 0; i < n - 1; i++) {
		min = i;
		for (int j = i + 1; j < n; j++) {
			if (data[j] < data[min]) {
				min = j;
			}
		}
		swap(data[min], data[i]);

	}



}
/*****************************************************************************/




void BubbleSort(int data[], int size)
{
	// write your code here
	for (int i = 0; i < size - 1; i++) {
		for (int j = size - 1; j > i; j--) {
			if (data[j] < data[j - 1]) {
				swap(data[j], data[j - 1]);

			}
		}
	}
}
/*****************************************************************************/




void InsertionSort(int data[], int n)
{
	// write your code here
	for (int i = 0; i < n; i++) {
		int x = data[i];
		for (int j = i - 1; j >= 0; j--) {
			if (data[j] > x) {
				data[j + 1] = data[j];
			}
			else {
				break;
			}
			data[j] = x;
		}
	}


}
/*****************************************************************************/




void SelectionSort2(int data[], int size)
{
	// write your code here
	int min1, min2;
	for (int i = 0; i < size - 1; i += 2) {
		min1 = i;
		min2 = i + 1;
		if (data[min1] > data[min2]) {
			swap(data[min1], data[min2]);
		}
		for (int j = i + 2; j < size; j++) {
			if (data[j] < data[min1]) {
				min2 = min1;
				min1 = j;

			}
			else if (data[j]<data[min2]) {
				min2 = j;
			}

		}
		swap(data[min2], data[i + 1]);
		swap(data[min1], data[i]);

	}

}
/*****************************************************************************/




void Swap(int &x, int &y)
{
	int t = x;
	x = y;
	y = t;
}
/*****************************************************************************/




void printData(int data[], int size, string title) {
	int i;

	cout << endl << title << endl;
	for (i = 0; i<size; i++)
	{
		cout << data[i] << " ";
		if (i % 10 == 9 && size > 10)
			cout << endl;
	}
}