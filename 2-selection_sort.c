#include "sort.h"

/**
 * getMinPosition - To get the index of the n number shorter
 * than the analyzed array value
 * @i: Actual index of an array
 * @actual: value contained in the gived index
 * @array: Array to analyze into
 * @size: size of the array
 * Return: Index that reprsents the coincidence
 */
int getMinPosition(int i, int actual, int *array, size_t size)
{
	int j = i, min_value = 0, index_related = 0;

	min_value = actual;
	while (j < (int)size)
	{
		if (array[j] < min_value)
		{
			min_value = array[j];
			index_related = j;
		}
		j++;
	}
	return (index_related);
}

/**
 * makeSwap - swap the values of two gived elements of an array
 * @left_index: First index
 * @right_index: Second index
 * @array: array to interact into
 * @size: Size of the array
 * Return: Nothing
 */
void makeSwap(int left_index, int right_index, int *array, size_t size)
{
	int tmp = 0;

	tmp = array[left_index];
	array[left_index] = array[right_index];
	array[right_index] = tmp;
	print_array(array, size);
}

/**
 * selection_sort - sorts an array of integers in ascending order using the
 *  Selection sort algorithm
 * @array: Array to sort
 * @size: size of the array
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	int i = 0, min_position;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < (int)size; i++)
	{
		min_position = getMinPosition(i, array[i], array, size);
		if (min_position != 0)
			makeSwap(i, min_position, array, size);
	}
}
