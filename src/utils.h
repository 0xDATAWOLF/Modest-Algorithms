#ifndef UTILS_H
#define UTILS_H
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <chrono>

/**
 * Produces a random number using the current time as seed, fixes it to an inclusive
 * range of min to max.
 */
inline int
getrand(int min, int max)
{
	srand(time(NULL));
	int value = min + rand() % (max + 1 - min);
	return value;
}

/** Calculates the length of unknown fixed-array. */
#define array_length(array) (sizeof(array)/sizeof(array[0]))

/**
 * Swaps two integers in array using two given indicies, a and b.
 */
inline void
swap_int(int* array, int a, int b)
{
	int c = array[a];
	array[a] = array[b];
	array[b] = c;
}

/**
 * Prints the contents of an array in rows of 8.
 */
inline void
print_array(int* array, int count)
{
	std::cout << std::right;
	int nrow = 0;
	for (int i = 0; i < count; ++i)
	{
		std::cout << std::setw(8) << array[i];
		if (nrow < 7)
		{
			std::cout << " ";
			nrow++;
		}
		else
		{
			std::cout << std::endl;
			nrow = 0;
		}
	}
	if (nrow != 0) std::cout << std::endl;
}

/**
 * Prints a series of dashes to the screen.
 */
inline void
print_sep()
{
	for (int b = 0; b < 64+16; ++b) std::cout << "-";
	std::cout << "\n";
}

/**
 * Serves as a simple benchmarking tool.
 */
class stopwatch
{

	public:
		stopwatch();
		stopwatch(std::string);
		~stopwatch();

	private:
		std::string tag;
		std::chrono::time_point<std::chrono::steady_clock> start;
		std::chrono::time_point<std::chrono::steady_clock> end;

};

stopwatch::stopwatch()
{
	tag = "";
	start = std::chrono::steady_clock::now();
}

stopwatch::stopwatch(std::string msg)
{
	tag = msg;
	start = std::chrono::steady_clock::now();
}

stopwatch::~stopwatch()
{

	end = std::chrono::steady_clock::now();
	long long int duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "[STOPWATCH] ";
	std::cout << tag << " took " << duration << "us (" << (double)duration/1000.0 << "ms).\n";

}

#endif