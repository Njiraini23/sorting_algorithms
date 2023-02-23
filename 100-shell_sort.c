#include "sort.h"

/**
 * shell_sort - sorts the integers in ascending order
 *@array : the array to be sorted
 *@size : the size of the array
 *
 * Return: the sorted array
 */

void shell_sort(int *array, size_t size)
{
	size_t interval = 1, index, checker, actual value;

	if (array == NULL || size < 2)
		return;
	while (interval < size / 3)
		interval = interval * 3 + 1;

	while (interval > 0)
	{
		for (index = interval; index < size; index++)
		{
			actual_value = array[index];
			checker = index;
			while (checker >= interval &&
					array[checker - interval] >= (int)actual value)
			{
				array[checker] = array[checker - interval];
				checker -= interval;
			}
			array[checker] = actual_value;
		}
		interval = (interval - 1) / 3;
		print_array(array, size);
	}
}
