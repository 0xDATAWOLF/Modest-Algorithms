#include <iostream>
#include <iomanip>
#include <string>

#include "dataset.h"
#include "algorithms.h"

#define SAMPLE_COUNT 10000

int main(int argc, char* argv[])
{

	// Generate an array of one million integers and do a two-pass shuffle.
	v_array sampleset;
	sampleset.generate(SAMPLE_COUNT);
	sampleset.shuffle(4);

	// Generate a working array from the sampleset that we can use to sort.
	v_array sortingset;
	sortingset.copyfrom(sampleset);

	// Benchmark sorting algorithms.
	selection_sort(sortingset.ptr(), sortingset.count());
	sortingset.show(8, 8, 4);
	sortingset.clear();
	sortingset.copyfrom(sampleset);

	// Benchmark sorting algorithms.
	insertion_sort(sortingset.ptr(), sortingset.count());
	sortingset.show(8, 8, 4);
	sortingset.clear();
	sortingset.copyfrom(sampleset);

	// Benchmark sorting algorithms.
	bubble_sort(sortingset.ptr(), sortingset.count());
	sortingset.show(8, 8, 4);
	sortingset.clear();
	sortingset.copyfrom(sampleset);

}

