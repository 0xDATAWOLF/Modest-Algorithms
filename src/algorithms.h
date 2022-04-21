#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include "dataset.h"

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

void
selection_sort(int* array, int count)
{

	return;
}

void
insertion_sort(int* array, int count)
{

	return;
}

void
bubble_sort(int* array, int count)
{

	return;
}

#endif