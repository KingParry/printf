#include "main.h"

/**
 * get_width - Calculates the width to be printed
 * @format: Format string to to print arguments.
 * @j: List of arguments to print.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *j, va_list list)
{
	int new_j;
	int width = 0;

	for (new_j = *j + 1; format[new_j] != '\0'; new_j++)
	{
		if (is_digit(format[new_j]))
		{
			width *= 10;
			width += format[new_j] - '0';
		}
		else if (format[new_j] == '*')
		{
			new_j++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*j = new_j - 1;

	return (width);
}
