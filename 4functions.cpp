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

