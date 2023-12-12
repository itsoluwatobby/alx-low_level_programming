#include "search_algos.h"
#include <math.h>

/**
 * jump_search - A function that searches for a value in a sorted array
 *		of integers using the jump search algorithm
 * @array: pointer to a sorted array
 * @size: size of the array
 * @value: target to be found
 *
 * Return: if SUCCESS index of the value else -1
 */

int jump_search(int *array, size_t size, int value)
{
	size_t step = 0, _jump = 0, i = 0;

	if (size == 0 || array == NULL)
		return (-1);
	step = sqrt(size);
	for (i = 0; _jump < size && array[_jump] < value;)
	{
		printf("Value checked array[%ld] = [%d]\n", _jump, array[_jump]);
		i = _jump;
		_jump += step;
	}
	printf("Value found between indexes [%ld] and [%ld]\n", i, _jump);

	_jump = _jump < size - 1 ? _jump : size - 1;
	for (; i < _jump && array[i] < value; i++)
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
	printf("Value checked array[%ld] = [%d]\n", i, array[i]);

	return (array[i] == value ? (int)i : -1);
}
