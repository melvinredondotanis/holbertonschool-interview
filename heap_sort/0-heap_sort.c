#include "sort.h"

/**
 * heap_sort - uses heapify sift-down to sort A in-place
 * @A: A to sort in-place
 * @size: size of A
 */
void heap_sort(int *A, size_t size)
{
	if (size < 2)
		return;

	heapify(A, size);

	for (size_t len = size; len > 1; --len)
	{
		swap(A, 0, len - 1, size);
		sift_down(A, 0, len - 1);
	}
}

/**
 * heapify - turns array into max heap
 * @A: pointer to array
 * @size: size of array
 */
void heapify(int *A, size_t size)
{
	for (ssize_t start = UP(size - 1); start >= 0; --start)
		sift_down(A, start, size);
}

/**
 * sift_down - performs heap sift-down operation
 * @A: pointer to array
 * @start: starting index
 * @len: current length of heap
 */
void sift_down(int *A, size_t start, size_t len)
{
	size_t root = start;

	while (LEFT(root) < len)
	{
		size_t child = LEFT(root);
		size_t swap_idx = root;

		if (A[child] > A[swap_idx])
			swap_idx = child;

		if (child + 1 < len && A[child + 1] > A[swap_idx])
			swap_idx = child + 1;

		if (swap_idx == root)
			break;

		swap(A, root, swap_idx, len);
		root = swap_idx;
	}
}

/**
 * swap - swaps two elements in array
 * @A: pointer to array
 * @a: index of first element
 * @b: index of second element
 * @size: size of array
 */
void swap(int *A, size_t a, size_t b, size_t size)
{
	if (a != b)
	{
		int temp = A[a];
		A[a] = A[b];
		A[b] = temp;
		print_array(A, size);
	}
}
