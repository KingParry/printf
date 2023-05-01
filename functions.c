#include "main.h"

/**
 * print_char - main function
 * @types: argmnts
 * @buffer: input
 * @flags:  input
 * @width: Width
 * @precision: input
 * @size: Size
 * Return: always 0
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/**
 * print_string - main entry
 * @types: arguments
 * @buffer: inputt
 * @flags:  flags
 * @width: input
 * @precision: Precision
 * @size: Size
 * Return: Number
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, z;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (z = width - length; z > 0; z--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (z = width - length; z > 0; z--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}

/**
 * print_percent - main entry
 * @types: arguments
 * @buffer: input
 * @flags:  input
 * @width: input
 * @precision: Precision
 * @size: Size
 * Return: always 0
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 * print_int - print
 * @types: arg
 * @buffer: input
 * @flags:  flags
 * @width: width.
 * @precision: Precision spec
 * @size: Size
 * Return: characters
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int w = va_arg(types, long int);
	unsigned long int num;

	w = convert_size_number(w, size);

	if (w == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)w;

	if (w < 0)
	{
		num = (unsigned long int)((-1) * w);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

/**
 * print_binary - print
 * @types: arguments
 * @buffer: handle print
 * @flags:  flags
 * @width: width.
 * @precision: Precision
 * @size: Size
 * Return: Numbers of char printed
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, x, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (x = 1; x < 32; x++)
	{
		m /= 2;
		a[x] = (n / m) % 2;
	}
	for (x = 0, sum = 0, count = 0; x < 32; x++)
	{
		sum += a[x];
		if (sum || x == 31)
		{
			char z = '0' + a[x];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
