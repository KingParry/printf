#include "main.h"


/**
 * get_precision - Calculates the precision for printing
 * @format: Format string to print arguments
 * @j: Arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *j, va_list list)
{
        int new_j = *j + 1;
        int precision = -1;


        if (format[new_j] != '.')
                return (precision);


        precision = 0;


        for (new_j += 1; format[new_j] != '\0'; new_j++)
        {
                if (is_digit(format[new_j]))
                {
                        precision *= 10;
                        precision += format[new_j] - '0';
                }
                else if (format[new_j] == '*')
                {
                        new_j++;
                        precision = va_arg(list, int);
                        break;
                }
                else
                        break;
        }


        *j = new_j - 1;


        return (precision);
}

