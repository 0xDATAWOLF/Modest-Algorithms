#ifndef DATASET_H
#define DATASET_H
#include <stdlib.h>

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

		int count() { return _array_count; };
		int max_size() { return _array_size; };

	private:
		void* _array_ptr;
		size_t _array_size;
		size_t _array_count;

};

/**
 * Default constructor behavior of the dataset.
 */
v_array::v_array()
{

	// Zero-initialize the members.
	_array_ptr = nullptr;
	_array_size = 0;
	_array_count = 0;

}

/**
 * Deconstruction will free the memory of the array.
 */
v_array::~v_array()
{
	free(_array_ptr);
}

int
v_array::operator[](int index)
{
	return ((int*)_array_ptr)[index];
}

/**
 * Push an element on to the top of the array stack. Will resize the array
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