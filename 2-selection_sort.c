#include "sort.h"
/**
 * swap - Swaps two integer values.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 **/

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * selection_sort - Sorts an integer array in ascending order using
 * the Selection Sort algorithm.
 * @array: Pointer to the array.
 * @size: Size of the array.
 **/
void selection_sort(int *array, size_t size)
{
	size_t rand_index, inner_index, min_index;
	rand_index = 0;

	while (rand_index < size - 1)
	{
		inner_index = rand_index + 1;
		min_index = rand_index;


	while (inner_index < size)
	{
		if (array[inner_index] < array[min_index])
		min_index = inner_index;

		inner_index++;
	}

	if (min_index != rand_index)
	{
		swap(&array[rand_index], &array[min_index]);
		print_array(array, size);
	}

	rand_index++;

	}
}
