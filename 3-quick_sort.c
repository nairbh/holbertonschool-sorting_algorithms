#include "sort.h"

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int *array, size_t size, int low, int high) {
	int pivot = array[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		if (array[j] < pivot) {
			i++;
			swap(&array[i], &array[j]);
		}
	}

	swap(&array[i + 1], &array[high]);
	print_array(array, size);
	return (i + 1);
}

void quick_sort_recursive(int *array, size_t size, int low, int high) {
	if (low < high) {
		int pi = partition(array, size, low, high);
		quick_sort_recursive(array, size, low, pi - 1);
		quick_sort_recursive(array, size, pi + 1, high);
	}
}

void quick_sort(int *array, size_t size) {
	quick_sort_recursive(array, size, 0, size - 1);
}
