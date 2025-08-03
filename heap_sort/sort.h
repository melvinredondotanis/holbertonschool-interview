#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define UP(x) ((x - 1) / 2)
#define LEFT(x) (2 * x + 1)
#define RIGHT(x) (2 * x + 2)

void print_array(const int *array, size_t size);
void heap_sort(int *A, size_t size);
void heapify(int *A, size_t size);
void sift_down(int *A, size_t start, size_t len, size_t size);
void swap(int *A, size_t a, size_t b, size_t size);

#endif /* SORT_H */
