#include "main.h"

/**
 * print_hex - Prints unsigned lowercase hex numbers.
 */
int print_hex(va_list ap, params_t *params)
{
	unsigned long l = va_arg(ap, unsigned long);
	char *str = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);

	if (params->hashtag_flag && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	params->unsign = 1;
	return print_number(str, params);
}

/**
 * print_HEX - Prints unsigned uppercase hex numbers.
 */
int print_HEX(va_list ap, params_t *params)
{
	unsigned long l = va_arg(ap, unsigned long);
	char *str = convert(l, 16, CONVERT_UNSIGNED, params);

	if (params->hashtag_flag && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	params->unsign = 1;
	return print_number(str, params);
}

/**
 * print_binary - Prints unsigned binary numbers.
 */
int print_binary(va_list ap, params_t *params)
{
	unsigned int n = va_arg(ap, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, params);

	if (params->hashtag_flag && n)
		*--str = '0';
	params->unsign = 1;
	return print_number(str, params);
}

/**
 * print_octal - Prints unsigned octal numbers.
 */
int print_octal(va_list ap, params_t *params)
{
	unsigned long l = va_arg(ap, unsigned long);
	char *str = convert(l, 8, CONVERT_UNSIGNED, params);

	if (params->hashtag_flag && l)
		*--str = '0';
	params->unsign = 1;
	return print_number(str, params);
}

