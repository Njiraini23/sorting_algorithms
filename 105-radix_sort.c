#include "sort.h"

int *create_array(int size);

/**
 * use_counting_sort - Implementing counting sort algorithm
 * @counter_array: Array used to store the Histogram density distribution
 * @array: Array to sort
 * @size: Size of the array
 * @sorted_array: Copy of the original array
 * @digit: Digit used to sort (Less significative)
 * Return: Nothing
 */
void use_counting_sort(int *counter_array, int *array, size_t size,
					   int *sorted_array, int digit)
{
	int i;

	for (i = size - 1; (int)i >= 0; i--)
	{
		sorted_array[counter_array[(array[i] / digit) % 10] - 1] = array[i];
		counter_array[(array[i] / digit) % 10] -= 1;
	}
	for (i = 0; i < (int)size; i++) /* Filling original array*/
		array[i] = sorted_array[i];
}

/**
 * use_radix_sort - Implementing radix sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 * @digit: Digit used to sort (Less significative)
 * @sorted_array: Copy of the original array
 * Return: 1 if sorted array was allocated, 0 if not
 */

int use_radix_sort(int *array, size_t size, int digit, int *sorted_array)
{
	int i, *counter_array = NULL;

	counter_array = create_array(10);
	if (!counter_array)
	{
		free(sorted_array);
		return (0);
	}
	for (i = 0; i < (int)size; i++)
		counter_array[(array[i] / digit) % 10] += 1;
	for (i = 0; i < 10; i++) /* Histogram frecuency distribution*/
		counter_array[i] += counter_array[i - 1];
	use_counting_sort(counter_array, array, size, sorted_array, digit);
	print_array(array, size);
	free(counter_array);
	return (1);
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
 * create_array - Create an array of 10 positions started in zeros
 * @size: size of the array to be created
 * Return: Array created
 *
 */
int *create_array(int size)
{
	int *array = NULL, i;

	array = malloc(sizeof(*array) * size);
	if (array == NULL)
		return (0);
	for (i = 0; i < size; i++)
		array[i] = 0;
	return (array);
}

/**
 * radix_sort - sorts an array of integers in ascending order
 * using the Radix sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 * Return: Nothing
 */
void radix_sort(int *array, size_t size)
{
	int *sorted_array = NULL, max_value, digit = 0, copy_max_value;

	if (array == NULL || size < 2)
		return;
	sorted_array = create_array(size);
	if (!sorted_array)
		return;
	get_max_value(array, size, &max_value);
	copy_max_value = max_value;
	for (digit = 1; copy_max_value != 0; copy_max_value /= 10, digit *= 10)
		if (!use_radix_sort(array, size, digit, sorted_array))
			return;
	free(sorted_array);
}

