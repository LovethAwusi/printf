#include <stdio.h>
#include <stdlib.h>
#include "MAIN.H"

/**
 * _printf - This is the function of my printf
 * @format: This is the string format to print
 *
 * Return: This is the no of character that prints
 */
int _printf(const char *format, ...)
{
	va_list args;
	int length = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	length = _print_format(format, args);
	va_end(args);
	return (length);
}
