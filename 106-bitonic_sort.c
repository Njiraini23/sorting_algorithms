#include "sort.h"

/**
 * make_swap - swap the values of two gived elements of an array
 * @left_index: pointer to first index
 * @right_index: pointer to second index
 * Return: Nothing
 */
void make_swap(int *left_index, int *right_index)
{
	int tmp = *left_index;

	*left_index = *right_index;
	*right_index = tmp;
}

/**
 * implement_bitonic_merge - Implements the recursive merge
 * @array: Pointer to the sub arrays
 * @updatable_size: Size of each sub array
 * @direction: Indicates the direction of the sort r if left to right
 * Return: Nothing
 */
void implement_bitonic_merge(int *array, size_t updatable_size, char direction)
{
	int i = 0, direction_is_r = direction == 'r' ? 1 : 0;

	if (updatable_size < 2)
		return;

	for (; i < (int)updatable_size / 2; i++)
		if ((array[i] > array[i + updatable_size / 2]) == direction_is_r)
			make_swap(array + i, array + i + updatable_size / 2);
	implement_bitonic_merge(array, updatable_size / 2, direction);
	implement_bitonic_merge(array + updatable_size / 2,
							updatable_size / 2, direction);
}

/**
 * implement_bitonic_sequency - Implements bitonic algorithm
 * @array: Pointer to the sub arrays
 * @updatable_size: Size of each sub array
 * @original_size: Size of the original array
 * @direction: Indicates the direction of the sort r if left to right
 * l if right to left
 * Return: Nothing
 */
void implement_bitonic_sequency(int *array, size_t updatable_size,
								size_t original_size, char direction)
{
	if (updatable_size < 2)
		return;
	printf("Merging [%li/%li] (%s):\n", updatable_size, original_size,
		   direction == 'r' ? "UP" : "DOWN");
	print_array(array, updatable_size);
	implement_bitonic_sequency(array, updatable_size / 2, original_size, 'r');
	implement_bitonic_sequency(array + updatable_size / 2, updatable_size / 2,
							   original_size, 'l');
	implement_bitonic_merge(array, updatable_size, direction);
	printf("Result [%li/%li] (%s):\n", updatable_size, original_size,
		   direction == 'r' ? "UP" : "DOWN");
	print_array(array, updatable_size);
}

/**
 * bitonic_sort - sorts an array of integers in ascending order
 *  using the Bitonic sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 * Return: Nothing
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	implement_bitonic_sequency(array, size, size, 'r');
}
