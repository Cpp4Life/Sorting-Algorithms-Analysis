#include "Timing.h"
#include "DataGenerator.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "BubbleSort.h"
#include "HeapSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "RadixSort.h"

using namespace std;

int main()
{
	int* a, n;
	int size[5] = { 3000, 10000, 30000, 100000, 300000 };

	for (int i = 0; i < 4; i++)
	{
		if (0 == i)
			cout << "Random Order Data :" << endl;
		else if (1 == i)
			cout << "Sorted Order Data :" << endl;
		else if (2 == i)
			cout << "Reverse Order Data : " << endl;
		else
			cout << "Nearly Sorted Data : " << endl;

		cout << "---------------------------------------" << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "Size : " << size[j] << endl;
			cout << "++++++++++++++++++++++++++++++++" << endl;
			n = size[j];
			a = new int[n];
			GenerateData(a, n, i);

			int* copy = new int[n];
			std::copy(a, a + n, copy);

			//Selection sort
			{
				Timer timer;
				SelectionSort(a, n);
				cout << "Time taken by Selection Sort: ";
			}
			std::copy(copy, copy + n, a);

			//Insertion sort
			{
				Timer timer;
				insertionSort(a, n);
				cout << "Time taken by Insertion Sort: ";
			}
			std::copy(copy, copy + n, a);

			//Bubble sort
			{
				Timer timer;
				BubbleSort(a, n);
				cout << "Time taken by Bubble Sort: ";
			}
			std::copy(copy, copy + n, a);

			//Heap sort
			{
				Timer timer;
				heapSort(a, n);
				cout << "Time taken by Heap Sort: ";
			}
			std::copy(copy, copy + n, a);

			//Merge sort
			{
				Timer timer;
				mergeSort(a, 0, n - 1);
				cout << "Time taken by Merge Sort: ";
			}
			std::copy(copy, copy + n, a);

			//Quick sort
			{
				Timer timer;
				quickSort(a, 0, n - 1);
				cout << "Time taken by Quick Sort: ";
			}
			std::copy(copy, copy + n, a);

			//Radix sort
			{
				Timer time;
				radixSort(a, n);
				cout << "Time taken by Radix Sort: ";
			}

			delete[] a;
			delete[] copy;
			cout << "++++++++++++++++++++++++++++++++\n\n";

		}
		cout << "---------------------------------------\n\n";
	}
}