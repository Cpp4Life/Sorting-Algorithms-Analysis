#pragma once
#include <algorithm>

void BubbleSort(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				std::swap(a[j], a[j + 1]);
			}
		}
	}
}