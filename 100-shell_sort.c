#include "sort.h"
/**
 * shell_sort - sorts an array of integers in ascending order using
 * the Shell sort algorithm, using the Knuth sequence
 * @array: Array to sort to
 * @size: Size of the array
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t interval = 1, index, checker, actual_value;
	/* Getting the started interval*/

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
				   array[checker - interval] >= (int)actual_value)
			{
				array[checker] = array[checker - interval];
				checker -= interval;
			}
			array[checker] = actual_value;
		}
		interval = (interval - 1) / 3; /* Reducing interval */
		print_array(array, size);
	}
}
