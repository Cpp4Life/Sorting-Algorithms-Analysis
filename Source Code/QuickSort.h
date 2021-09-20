#pragma once

#include <algorithm>

int partition(int arr[], int left, int right, int pivot)
{
	while (left <= right)
	{
		while (arr[left] < pivot)
			left++;
		while (arr[right] > pivot)
			right--;
		if (left <= right)
		{
			std::swap(arr[left], arr[right]);
			left++;
			right--;
		}
	}
	return left;
}

void quickSort(int arr[], int left, int right)
{
	if (left >= right)
		return;
	int pivot = arr[(left + right) / 2];
	int index = partition(arr, left, right, pivot);

	quickSort(arr, left, index - 1);
	quickSort(arr, index, right);
}