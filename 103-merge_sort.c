#include "sort.h"

/**
 * merge_arrays - Merge arrays
 * @array: Incoming array
 * @start: Left index
 * @mid: Middle index
 * @end: Right index
 * @to_store: Array temporal to store the sorted information
 * Return: Nothing
 */
void merge_arrays(int *array, int start, int mid, int end, int *to_store)
{
	int from_initial = start, from_mid = mid, k = 0;

	printf("Merging...\n[left]: ");
	print_array(array + start, mid - start);
	printf("[right]: ");
	print_array(array + mid, end - mid);
	for (; from_initial < mid && from_mid < end; k++)
	{
		if (array[from_initial] < array[from_mid])
			to_store[k] = array[from_initial++];
		else
			to_store[k] = array[from_mid++];
	}
	for (; from_initial < mid; from_initial++, k++)
		to_store[k] = array[from_initial];

	for (; from_mid < end; from_mid++, k++)
		to_store[k] = array[from_mid];

	for (k = 0, from_initial = start; from_initial < end; from_initial++, k++)
		array[from_initial] = to_store[k];

	printf("[Done]: ");
	print_array(array + start, end - start);
}

/**
 * merge_sort_recurtion - sorts an array of integers in ascending order using
 *  the Merge sort algorithm
 * @array: Array to sort
 * @start: Left index
 * @end: Right index
 * @to_store: Array temporal to store the sorted information
 *
 * Return: Nothing
 *
 */
void merge_sort_recurtion(int *array, int start, int end, int *to_store)
{
	int mid;

	if (end > start + 1)
	{
		mid = start + (end - start) / 2;
		merge_sort_recurtion(array, start, mid, to_store);
		merge_sort_recurtion(array, mid, end, to_store);
		merge_arrays(array, start, mid, end, to_store);
	}
}

/**
 * merge_sort - sorts an array of integers in ascending order using
 * the Merge sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 *
 */
void merge_sort(int *array, size_t size)
{

	int *to_store;

	if (array == NULL || size < 2)
		return;
	to_store = malloc(sizeof(int) * size);
	if (to_store == NULL)
		return;
	merge_sort_recurtion(array, 0, size, to_store);
	free(to_store);
}

