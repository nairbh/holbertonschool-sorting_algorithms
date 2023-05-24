#include "sort.h"

/**
 * swap - swaps the values of two integers
 *
 * @a: first integer to be swapped
 * @b: second integer to be swapped
 */

void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * partition - sections an array using quick_sort algo
 * with Lomuto scheme
 *
 * @array: array of integers
 * @low: lowest index of the array
 * @high: highest index of the array
 * @size: size of the array
 * Return: position of pivot in array
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot_value = array[high];
	int i = low - 1, j;

	for (j = low; j <= high; j++)
	{
		if (array[j] <= pivot_value)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	return (i);
}

/**
 * quick_sort_recursive - recursive quick sort function
 *
 * @array: array to be sorted
 * @low: starting index of the subarray
 * @high: ending index of the subarray
 * @size: size of the array
 */

void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot - 1, size);
		quick_sort_recursive(array, pivot + 1, high, size);
	}
}
/**
 * quick_sort - sorts the array in ascending order
 * using the quicksort algorithm
 *
 * @array: array to be sorted
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (!array)
		return;
	quick_sort_recursive(array, 0, size - 1, size);
}
