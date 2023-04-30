#include "main.h"

/**
 * is_printable - reviews a char for printing
 * @k: Char to be reviewed.
 *
 * Return: 1 if k is printable, 0 otherwise
 */
int is_printable(char k)
{
	if (k >= 32 && k < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Append ascii in hexadecimal code to buffer
 * @buffer: Array of chars.
 * @j: Index to start appending.
 * @ascii_code: ASCII CODE.
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int j)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[j++] = '\\';
	buffer[j++] = 'x';

	buffer[j++] = map_to[ascii_code / 16];
	buffer[j] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Verifies if a char is a digit or not
 * @k: Char to evaluate
 *
 * Return: 1 if k is a digit, 0 otherwise
 */
int is_digit(char k)
{
	if (k >= '0' && k <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - registers a number to the specified size
 * @num: Number register.
 * @size: Number indicating the type to register
 *
 * Return: register value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - registers a number to a specified size
 * @num: Number to register
 * @size: Number indicating type to register
 *
 * Return: register value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
