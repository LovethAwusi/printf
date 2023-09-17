#include "main.h"

/**
 * get_specifier - Find the format function associated with the specifier.
 * @s: Format specifier
 *
 * Return: Pointer to the format function
 */
int (*get_specifier(char *s))(va_list ap, params_t *params)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};

	for (int i = 0; specifiers[i].specifier; i++) {
		if (*s == specifiers[i].specifier[0])
			return specifiers[i].f;
	}

	return NULL;
}

/**
 * get_print_func - Find the format function and call it.
 * @s: Format specifier
 * @ap: Argument pointer
 * @params: Parameters struct
 *
 * Return: Number of bytes printed
 */
int get_print_func(char *s, va_list ap, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(s);
	return (f) ? f(ap, params) : 0;
}

/**
 * get_flag - Parse and set format flags.
 * @s: Format string
 * @params: Parameters struct
 *
 * Return: 1 if flag was valid, else 0
 */
int get_flag(char *s, params_t *params)
{
	switch (*s) {
		case '+':
			params->plus_flag = 1;
			return 1;
		case ' ':
			params->space_flag = 1;
			return 1;
		case '#':
			params->hashtag_flag = 1;
			return 1;
		case '-':
			params->minus_flag = 1;
			return 1;
		case '0':
			params->zero_flag = 1;
			return 1;
		default:
			return 0;
	}
}

/**
 * get_modifier - Parse and set format modifiers.
 * @s: Format string
 * @params: Parameters struct
 *
 * Return: 1 if modifier was valid, else 0
 */
int get_modifier(char *s, params_t *params)
{
	switch (*s) {
		case 'h':
			params->h_modifier = 1;
			return 1;
		case 'l':
			params->l_modifier = 1;
			return 1;
		default:
			return 0;
	}
}

/**
 * get_width - Parse and set the width from the format string.
 * @s: Format string
 * @params: Parameters struct
 * @ap: Argument pointer
 *
 * Return: New pointer
 */
char *get_width(char *s, params_t *params, va_list ap)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	params->width = d;
	return s;
}

