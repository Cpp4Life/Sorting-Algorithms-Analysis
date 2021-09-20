#pragma once
#include <algorithm>

void SelectionSort(int a[], int size)
{
	int min;
	for (int i = 0; i < size; i++)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (a[j] < a[min])
			{
				min = j;
			}
		}
		std::swap(a[i], a[min]);
	}
}