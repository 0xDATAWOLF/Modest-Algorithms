#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

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

	std::vector<double> sel_timings;

	for (int i = 0; i < 100; ++i)
	{
		selection_sort(sortingset.ptr(), sortingset.count());
		sel_timings.push_back(stopwatch::lasttime_ms());

		// Regenerate, shuffle, and copy back into sorting set.
		sampleset.generate(SAMPLE_COUNT);
		sampleset.shuffle(4);
		sortingset.copyfrom(sampleset);

	}

	double average;
	for (double time : sel_timings) average += time;
	average /= sel_timings.size();
	std::cout << "The average computation time was: " << average << "ms.\n";
	std::cout << "The first computation time was: " << sel_timings[0] << "ms.\n";
	std::cout << "The last computation time was: " << sel_timings[sel_timings.size()-1] << "ms.\n";

#if 0
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
#endif

}

