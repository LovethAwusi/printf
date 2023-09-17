#include "main.h"

/**
 * print_char - Prints a character.
 */
int print_char(va_list ap, params_t *params)
{
	char ch = va_arg(ap, int);
	unsigned int pad = params->width - 1;
	int sum = 0;

	if (params->minus_flag)
		sum += _putchar(ch);

	while (pad-- > 0)
		sum += _putchar(' ');

	if (!params->minus_flag)
		sum += _putchar(ch);

	return (sum);
}

/**
 * print_int - Prints an integer.
 */
int print_int(va_list ap, params_t *params)
{
	long l;

	if (params->l_modifier)
		l = va_arg(ap, long);
	else if (params->h_modifier)
		l = (short int)va_arg(ap, int);
	else
		l = (int)va_arg(ap, int);

	return (print_number(convert(l, 10, 0, params), params));
}

/**
 * print_string - Prints a string.
 */
int print_string(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *);
	int sum = 0;

	if (!str)
		str = NULL_STRING;

	unsigned int len = (params->precision != UINT_MAX) ? params->precision : _strlen(str);

	if (params->minus_flag)
		sum += _puts(str, len);

	while (params->width-- > len)
		sum += _putchar(' ');

	if (!params->minus_flag)
		sum += _puts(str, len);

	return (sum);
}

/**
 * print_percent - Prints a percent symbol.
 */
int print_percent(va_list ap, params_t *params)
{
	(void)ap;
	(void)params;
	return (_putchar('%'));
}

/**
 * print_S - Prints a string with special characters escaped.
 */
int print_S(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *);
	int sum = 0;

	if (!str)
		return (_puts(NULL_STRING));

	while (*str)
	{
		if ((*str < 32 && *str >= 0) || *str >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			sum += _puts(convert(*str, 16, 0, params));
		}
		else
		{
			sum += _putchar(*str);
		}
		str++;
	}
	return (sum);
}

