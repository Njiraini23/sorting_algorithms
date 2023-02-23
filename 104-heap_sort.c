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
 * build_max_heap - implementing heap sort by changing elements using sift-down
 * @array: Array to sort
 * @starter_index: Parent node in tree
 * @size: Size of the array used to print it
 * @updatable_size: Size of the array which is varaible
 * Return: Nothing
 */
void build_max_heap(int *array, int starter_index,
					size_t size, int updatable_size)
{
	int control_swap, left, right;

	while ((left = 2 * starter_index + 1) <= updatable_size)
	{
		control_swap = starter_index;
		right = left + 1;
		if (left <= updatable_size && array[control_swap] < array[left])
			control_swap = left;
		if (right <= updatable_size && array[control_swap] < array[right])
			control_swap = right;
		if (control_swap == starter_index)
			return;
		make_swap(array + starter_index, array + control_swap);
		print_array(array, size);
		starter_index = control_swap;
	}
}

/**
 * sort_heap - Sorts the heap first time
 * @array: Arrray to sort
 * @size: Size of the array
 * @starter_index: Parent node in tree
 * Return: Nothing
 */

void sort_heap(int *array, int size, int starter_index)
{
	while (starter_index >= 0)
	{
		build_max_heap(array, starter_index, size, size - 1);
		if (!starter_index)
			return;
		starter_index--;
	}
}
/**
 * heap_sort - sorts an array of integers in ascending order using
 * the Heap sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 * Return: Nothing
 */
void heap_sort(int *array, size_t size)
{

	int starter_index = (((int)size - 1) - 1) / 2,
		updatable_size = (int)size - 1;

	if (array == NULL || size < 2)
		return;
	sort_heap(array, size, starter_index);
	while (updatable_size > 0)
	{
		make_swap(array, array + updatable_size);
		print_array(array, size);
		updatable_size--;
		build_max_heap(array, 0, size, updatable_size);
	}
}
