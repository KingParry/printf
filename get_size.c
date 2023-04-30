#include "main.h"

/**
 * get_size - Calculates the size of the argument
 * @format: Formatt string to print arguments
 * @j: List of arguments.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *j)
{
	int new_j = *j + 1;
	int size = 0;

	if (format[new_j] == 'l')
		size = S_LONG;
	else if (format[new_j] == 'h')
		size = S_SHORT;

	if (size == 0)
		*j = new_j - 1;
	else
		*j = new_j;

	return (size);
}
