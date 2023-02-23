#include "sort.h"

/**
 * use_counting_sort - implementing counting sort algorithm
 * @array: Array to sort
 * @sorted_array: Copy of the originla array
 * @counter_array: Array used to storethe Histogram density distibution
 * @size: Size of the array
 * Return: Nothing
 */
void use_counting_sort(int *array, int *sorted_array,
					   int *counter_array, size_t size)
{
	int i;

	for (i = 0; i < (int)size; i++)
	{
		sorted_array[counter_array[array[i]] - 1] = array[i];
		counter_array[array[i]] -= 1;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = sorted_array[i];
}

/**
 *create_counter_array - Creates an array that contain as indexes
 * the values of another array
 * @max_value: Size of the array
 * @sorted_array: An array to free in case that memory can't be separate
 * Return: Nothing
 */
int *create_counter_array(int max_value, int *sorted_array)
{
	int *array = NULL, i;

	array = malloc(sizeof(int) * (max_value + 1));
	if (array == NULL)
	{
		free(sorted_array);
		return (NULL);
	}
	for (i = 0; i < max_value + 1; i++)
		array[i] = 0;
	return (array);
}

/**
 * get_max_value - Get the max value of a gived array
 * @array: Array needed to get the max value
 * @size: Size of the array
 * @max_value: Max value to get/set
 * Return: Nothing
 */
void get_max_value(int *array, size_t size, int *max_value)
{
	int i;

	for (i = 0, *max_value = *array; i < (int)size; i++)
		if (array[i] > *max_value)
			*max_value = array[i];
}

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *counter_array = NULL, max_value = 0, *sorted_array = NULL, i;

	if (array == NULL || size < 2)
		return;
	sorted_array = malloc(sizeof(int) * size);
	if (sorted_array == NULL)
		return;
	get_max_value(array, size, &max_value);
	counter_array = create_counter_array(max_value, sorted_array);
	if (!counter_array)
		return;
	for (i = 0; i < (int)size; i++)
		counter_array[array[i]] += 1;
	for (i = 1; i < max_value + 1; i++)
		counter_array[i] += counter_array[i - 1];
	print_array(counter_array, max_value + 1);

	use_counting_sort(array, sorted_array, counter_array, size);
	free(sorted_array);
	free(counter_array);
}

