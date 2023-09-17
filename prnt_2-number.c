#include "main.h"

/**
 * print_from_to - Print a range of characters.
 */
int print_from_to(char *start, char *stop, char *except)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != except)
			sum += _putchar(*start);
		start++;
	}
	return (sum);
}

/**
 * print_rev - Print a string in reverse.
 */
int print_rev(va_list ap, params_t *params)
{
	int sum = 0;
	char *str = va_arg(ap, char *);
	(void)params;

	if (str)
	{
		for (int len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			sum += _putchar(*str);
	}
	return (sum);
}

/**
 * print_rot13 - Print a string in ROT13 encoding.
 */
int print_rot13(va_list ap, params_t *params)
{
	int count = 0;
	char *str = va_arg(ap, char *);
	(void)params;

	if (str)
	{
		char *rot13 = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

		for (int i = 0; str[i]; i++)
		{
			if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
			{
				int index = str[i] - (str[i] >= 'a' ? 'a' : 'A');
				count += _putchar(rot13[index]);
			}
			else
			{
				count += _putchar(str[i]);
			}
		}
	}
	return (count);
}

