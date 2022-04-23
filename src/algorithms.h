#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include "dataset.h"

#define array_length(array) (sizeof(array)/sizeof(array[0]))

int
binary_search(int* array, int count, int value)
{

	int high = count-1;
	int low = 0;

	do
	{

		// Get the midpoint.
		int midpoint = (high+low)/2;

		// Check the midpoint first.
		if (array[midpoint] == value) return midpoint+1;

		// Otherwise, determine the next high/low.
		if (value < array[midpoint])
		{
			high = midpoint-1;
		}
		else
		{
			low = midpoint+1;
		}

	}
	while (high > low);

	return (array[low] < value) ? low+1 : low;

}

inline void
swap_int(int* array, int a, int b)
{
	int c = array[a];
	array[a] = array[b];
	array[b] = c;
}

void
selection_sort(int* array, int count)
{

	for (int i = 0; i < count; ++i)
	{
		int mindex = i;
		for (int n = i+1; n < count; ++n)
		{
			if (array[n] < array[mindex]) mindex = n;
		}
		swap_int(array, i, mindex);
	}

	return;
}

void
insertion_sort(int* array, int count)
{

	for (int i = 1; i < count; ++i)
	{
		int j = i;
		while (j > 0 && array[j-1] > array[j])
		{
			swap_int(array, j-1, j);
			--j;
		} 
	}

	return;
}

void
bubble_sort(int* array, int count)
{

	bool swapped = false;
	do
	{
		swapped = false;
		for (int i = 1; i < count; ++i)
		{
			if (array[i-1] > array[i])
			{
				swap_int(array, i-1, i);
				swapped = true;
			}
			
		}
		--count;
	}
	while (swapped == true);

	return;
}

#endif