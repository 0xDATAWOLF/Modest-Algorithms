#ifndef DATASET_H
#define DATASET_H

#include "utils.h"


/**
 * Defines a dataset class that allows for generic accumulation of integer data.
 * It functions much like a vector, allowing for the dynamic resizing of an array.
 * 
 * The internal storage type of the dataset is an integer.
 * 
 * TODO: Make this structure generic for more complex datatypes?
 */

class v_array
{
	public:
		v_array();
		~v_array();

		void push(int);


		int operator[](int);

		/** 
		 * Doesn't guarantee that the pointer will be valid when push is used when
		 * capturing onto the stack.
		 */
		int* ptr() { return (int*)_array_ptr; }

		void generate(int);
		void shuffle(int);

		void copyfrom(v_array&);
		void clear();

		void show(int, int, int);

		int count() { return _array_count; };
		int max_size() { return _array_size; };

	private:
		void* _array_ptr;
		size_t _array_size;
		size_t _array_count;

};

v_array::v_array()
{

	// Zero-initialize the members.
	_array_ptr = nullptr;
	_array_size = 0;
	_array_count = 0;

}

v_array::~v_array()
{
	clear(); // Will free the memory.
}

int
v_array::operator[](int index)
{
	return ((int*)_array_ptr)[index];
}

/**
 * Copies the contents of source v_array into this one.
 */
void
v_array::copyfrom(v_array& source)
{

	for (int i = 0; i < source.count(); ++i)
		push(source[i]);

}

/**
 * Clears the contents of the array and reinitializes it. It will free the current
 * contents from the heap in the process.
 */
void
v_array::clear()
{

	free(_array_ptr);
	_array_ptr = nullptr;
	_array_count = 0;
	_array_size = 0;

}

/**
 * Shows the array.
 */
void
v_array::show(int spacing, int rows, int cols)
{

	std::cout << std::right;

	int rcount = 0;
	int ccount = cols;
	for (int vindex = 0; vindex < _array_count; ++vindex)
	{

		if (rcount >= rows)
		{
			std::cout << std::endl;
			rcount = 0;
			ccount--;
		}

		if (ccount == 1)
		{
			vindex = (_array_count - (rows-1));
			std::cout << std::setw(spacing) << "...";
			ccount--;
		}

		std::cout << std::setw(spacing) << ((int*)_array_ptr)[vindex];
		++rcount;

	}

	std::cout << std::endl;

}

/**
 * Generates of a list of contiguous numbers starting from 1 to n-count.
 */
void
v_array::generate(int count)
{

	// Ensure that we are starting from a fresh array.
	this->clear();

	// Push.
	for (int i = 1; i <= count; ++i) push(i);

}

/**
 * Shuffles the entire list of numbers.
 */
void
v_array::shuffle(int shuffles)
{

	// Shuffles passes.
	for (int s = 0; s < shuffles; ++s)
	{
		
		// Feed forward Fisher-Yates
		if (s % 2)
		{
			for (int i = _array_count-1; i > 0; --i)
			{
				int swap_index = getrand(0, i);
				swap_int((int*)_array_ptr, i, swap_index);
			}
		}

		// Feed backwards Fisher-Yates
		else
		{
			for (int i = 0; i < _array_count; ++i)
			{
				int swap_index = getrand(i, _array_count-1);
				swap_int((int*)_array_ptr, i, swap_index);
			}
		}

	}

}

/**
 * Push an element on to the top of the array stack. Will resize the array by 2n
 * should it reach capacity.
 */
void
v_array::push(int element)
{

	// If the array is a nullptr, make room for two elements.
	if (_array_ptr == nullptr)
	{
		_array_ptr = malloc(sizeof(int)*2);
		_array_size = 2;
		_array_count = 0;
	}

	// Resize the array if it's not large enough to store what we need.
	if (_array_count >= _array_size)
	{

		// Resize the array by 2n and allocate a new array.
		int resize = _array_size*2; // Double the existing array size.
		void* narray = malloc(sizeof(int)*resize);

		// Copy the contents of the original array over to the new array and free the old array.
		memcpy_s(narray, resize*sizeof(int), _array_ptr, _array_size*sizeof(int));
		free(_array_ptr);

		// Update the internal state.
		_array_ptr = narray;
		_array_size = resize;
	}

	// Set place the new value into the array.
	((int*)_array_ptr)[_array_count++] = element;

}

#endif