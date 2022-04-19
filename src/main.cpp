#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Helper functions
inline void showHeader(char*);
static void getUnsorted(vector<int>&);
static void showVector(vector<int>&, int);

// Sorting functions
static int alg_binary_search(vector<int>&, int, int, int);
static void alg_bubble_sort(vector<int>&);
static void alg_selection_sort(vector<int>&);
static void alg_insertion_sort(vector<int>&);
static void alg_binary_insertion_sort(vector<int>&);

int main(int argc, char* argv[])
{
	
	vector<int> unsorted;
	getUnsorted(unsorted);

	alg_binary_insertion_sort(unsorted);
	showVector(unsorted, 8);

}

// --------------------------------------------------------------
// Helper Function Definitions
// --------------------------------------------------------------

inline void
showHeader(char* header)
{
	for (int b = 0; b < 64+16; ++b) cout << "-";
	cout << endl;
	cout << header << endl;
	for (int b = 0; b < 64+16; ++b) cout << "-";
	cout << endl;

}

/**
 * Fetches an unsorted listed from std::cin until
 */
static void
getUnsorted(vector<int>& data)
{
	string line;
	while(getline(cin, line))
	{
		data.push_back(atoi(line.c_str()));
	}
	return;
}

/**
 * Prints out a vector, right aligned, padded with 8 spaces. User defines how many numbers
 * to show per row. Default is 8.
 */
static void
showVector(vector<int>& data, int numsPerRow)
{

	cout << right;
	int nrow = 0;
	for (int i : data)
	{
		cout << setw(8) << i;
		if (nrow < numsPerRow-1)
		{
			cout << " ";
			nrow++;
		}
		else
		{
			cout << endl;
			nrow = 0;
		}
	}
	if (nrow != 0) cout << endl;
}

// --------------------------------------------------------------
// Algorithm Function Definitions
// --------------------------------------------------------------

/**
 * Binary Search
 * Searches for a location in which a number may exist using divisional splitting.
 */
static int
alg_binary_search(vector<int>& data, int query, int low, int high)
{

	// Catch case when high and low meet, that means we didn't find it and so
	// we will just chuck it in next-best-fit.
	if (high <= low)
	{
		return (query > data[low]) ? low + 1 : low;
	}

	int midpoint = (high+low)/2;

	// Check midpoint for valid position.
	if (data[midpoint] == query)
	{
		return midpoint+1;
	}

	// Lower bounds.
	if (query < data[midpoint])
	{
		return alg_binary_search(data, query, low, midpoint-1);
	}

	// Otherwise, upper bounds.
	else
	{
		return alg_binary_search(data, query, midpoint+1, high);
	}

}

/**
 * Bubble Sort
 * Cycles through an array of items, always swaps the largest with the smallest in
 * a given list until it reaches the end. Each iteration reduces at the last swap
 * position as it guarantees up to that point being sorted.
 */
static void
alg_bubble_sort(vector<int>& data)
{

	int lastSwap = 0;
	int n = data.size();
	do
	{
		lastSwap = 0;
		for(int i = 1; i < n; ++i)
		{
			if (data[i-1] > data[i])
			{
				swap(data[i-1], data[i]);
				lastSwap = i;
			}
		}
		n = lastSwap;
	}
	while(lastSwap > 1);

	return;
}

/**
 * Selection Sort
 * Searches for the minimum along a set of elements and swaps it the head of
 * for sorted sub-array. The sorted sub-array grows i+1 for each pass until
 * the sorted sub-array is the length of the starting unsorted array.
 */
static void
alg_selection_sort(vector<int>& data)
{

	for (int i = 0; i < data.size(); ++i)
	{
		int mIndex = i;
		for (int j = i+1; j < data.size(); ++j)
		{
			if (data[j] < data[mIndex]) mIndex = j;
		}
		swap(data[i], data[mIndex]);
	}

	return;
}

/**
 * Insertion Sort
 * Sorts from the head of the unsorted array by swapping it back into the head of
 * the sorted sub-array and then repeating moving it backwards until it is no longer
 * less than the element it is swapped with.
 */
static void
alg_insertion_sort(vector<int>& data)
{

	for (int i = 1; i < data.size(); ++i)
	{
		int temp = data[i];
		int j = i;
		while (j > 0 && data[j-1] > temp)
		{
			data[j] = data[j-1];
			--j;
		}
		data[j] = temp;
	}

	return;
}

/**
 * Binary Insertion Sort
 * A faster insertion sort implementing binary search to find the index to swap the unsorted
 * element to.
 */
static void
alg_binary_insertion_sort(vector<int>& data)
{

	for (int i = 1; i < data.size(); ++i)
	{
		int j = i-1;
		int el = data[i];
		int loc = alg_binary_search(data, el, 0, j);
		while (j >= loc)
		{
			data[j+1] = data[j];
			j--;
		}
		data[j+1] = el;
	}

}
