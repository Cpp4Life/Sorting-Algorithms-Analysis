#pragma once

#include <algorithm>

void heapify(int arr[], int size, int i)
{
	int largest = i; //assuming root is the largest
	int left = 2 * i + 1; //left child
	int right = 2 * i + 2; //right child
	if (left < size && arr[left] > arr[largest])
		largest = left;

	if (right < size && arr[right] > arr[largest])
		largest = right;

	if (largest != i)
	{
		std::swap(arr[i], arr[largest]);
		heapify(arr, size, largest);
	}
}

void heapSort(int arr[], int size)
{
	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(arr, size, i);

	for (int i = size - 1; i > 0; i--)
	{
		std::swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}
