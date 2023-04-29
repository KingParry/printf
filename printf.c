#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - main function
 * @format: input
 * Return: always 0
 */
int _printf(const char *format, ...)
{
	int z, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (z = 0; format && format[z] != '\0'; z++)
	{
		if (format[z] != '%')
		{
			buffer[buff_ind++] = format[z];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[z], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &z);
			width = get_width(format, &z, list);
			precision = get_precision(format, &z, list);
			size = get_size(format, &z);
			++z;
			printed = handle_print(format, &z, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - main entry
 * @buffer: Array
 * @buff_ind: input
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
