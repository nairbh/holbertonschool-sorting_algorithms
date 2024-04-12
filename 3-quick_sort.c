#include "sort.h"

void rec_quicksort(int *array, int low, int high, size_t size);
int lomutoPartition(int *array, int low, int high, size_t size);

/**
* swap - helper function that swaps the values of two given integers
* @a : first int
* @b : second int
* Return: void
*/
void swap(int *a, int *b, int *array, size_t size)
{
        int temp;

        temp = *a;
        *a = *b;
        *b = temp;
        print_array(array, size);
}

/**
* rec_quicksort - recursively sorts a subarray of ints with quicksort algorithm
* @array: pointer to the array to be sorted
* @size: size of the array
* @low: index of the start of the sub-array to be sorted
* @high: index of the end of the sub-array to be sorted
* Return: void
*/
void rec_quicksort(int *array, int low, int high, size_t size)
{
        int parti;

        if (low < high)
        {
                parti = lomutoPartition(array, low, high, size);
                rec_quicksort(array, low, parti - 1, size);
                rec_quicksort(array, parti + 1, high, size);
        }
}

/**
* lomutoPartition - function that applies the Lomuto partition scheme
*
* Description: last element of subarray = pivot, then :
*                               elements < pivot get to its left
*                               elements > pivot get to its right.
*
* @array: pointer to the sub-array to be sorted
* @low: index of the start of the sub-array
* @high: index of the end of the sub-array
* @size: size of the sub-array
* Return: index of the pivot after partitioning
*/
int lomutoPartition(int *array, int low, int high, size_t size)
{
        int pivot = array[high];
        int i = low - 1;
        int j;

        for (j = low ; j < high ; j++)
        {
                if (array[j] < pivot)
                {
                        i++;
                        swap(&array[i], &array[j], array, size);
                }
        }
        swap(&array[i + 1], &array[high], array, size);
        return (i + 1);
}

/**
 * quick_sort - Sorts an array of integers in ascending order using the
 *              quicksort algorithm with Lomuto partition scheme.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
        int low = 0;
        int high = size - 1;

        if (size < 2)
                return;

        rec_quicksort(array, low, high, size);
}
