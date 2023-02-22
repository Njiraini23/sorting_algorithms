#include "sort.h"

/**
 * makeSwap - swap the values of two gived elements of an array
 * @left_index: pointer to first index
 * @right_index: pointer to second index
 * @array: array to print
 * @size: Size of the array
 * Return: Nothing
 */
void makeSwap(int *left_index, int *right_index, int *array, size_t size)
{
	int tmp = 0;

	tmp = *left_index;
	*left_index = *right_index;
	*right_index = tmp;
	print_array(array, size);
}

/**
 * lomuto_partition - lomuto partition scheme
 * @array: Array to sort in ascendant order
 * @size: Size of the array
 * @first_index: Lowest index
 * @last_index: Highest index
 * Return: Partition index
 *
 */
int lomuto_partition(int *array, int first_index, int last_index, size_t size)
{
	int *pivot = NULL, actual_index, partition_index;

	pivot = array + last_index;
	for (partition_index = actual_index = first_index;
		 actual_index < last_index; actual_index++)
	{
		if (*pivot > array[actual_index])
		{
			if (partition_index != actual_index)
				makeSwap(array + partition_index, array + actual_index, array, size);
			partition_index++;
		}
	}
	if (*pivot < array[partition_index]) /*  condition when 2 elements*/
		makeSwap(array + partition_index, pivot, array, size);

	return (partition_index);
}

/**
 * quick_sort_recurtion - Implementing recrsive sort function for the
 * Quick sort algorithm
 * @array: Array to sort in ascendant order
 * @first_index: Lowest index
 * @last_index: Highest index
 * @size: Size of the array
 */
void quick_sort_recurtion(int *array, int first_index, int last_index,
						  size_t size)
{
	int partition_index = 0;

	if (first_index < last_index)
	{
		partition_index = lomuto_partition(array, first_index, last_index, size);
		quick_sort_recurtion(array, first_index, partition_index - 1, size);
		quick_sort_recurtion(array, partition_index + 1, last_index, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using
 *  the Quick sort algorithm
 * @array: Array to sort in ascendant order
 * @size: Size of the array
 * Return: Nothing
 *
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_recurtion(array, 0, size - 1, size);
}

