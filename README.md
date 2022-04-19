# The Modest Collection of Algorithms

This project contains a collection of algorithms for sorting and searching. The project will continue
to grow in time, eventually adding in visuals and performance benchmarks of different algorithms. For
now, the feature set will be purely utilitarian.

This project contains:

* **Binary Search**
	- **Time Complexity:** O(log<sub>2</sub>n) search time.
	- Used for finding an element within a sorted array.

* **Selection Sort**
	- **Time Complexity:** O(n<sup>2</sup>) sorting time.
	- Trivial implementation, great for determining if the array is already sorted.
	Many comparisons, low swaps.

* **Bubble Sort**
	- **Time Complexity:** O(n<sup>2</sup>) sorting time.
	- Trivial implementation, with best case being O(n) when the array is sorted.
	Many comparisons, many swaps.

* **Insertion Sort**
	-**Time Complexity:**  O(n<sup>2</sup>) sorting time.
	- Trivial implementation, great for small data sets, performs better the closer
	the array is to being sorted.

* **Binary-Insertion Sort**
	- **Time Complexity:** O(n<sup>2</sup>) sorting time.
	- Requires binary search in the implementation. On average, binary-insertion sort
	outperforms insertion sort because it reduces the amount of comparisons from O(n<sup>2</sup>)
	to O(logn). 

