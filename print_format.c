#include "holberton.h"
#include <stdlib.h>

/**
 * _print_format - Prints a formatted string.
 * @format: The format string to print.
 * @args: A list of variadic arguments.
 *
 * Return: The length of the format string.
 */
int _print_format(const char *format, va_list args)
{
    int count = 0;
    int i = 0;

    while (format && format[i])
    {
        if (format[i] == '%')
        {
            if (format[i + 1] == '\0')
                return (-1);

            i++;

            while (format[i] == ' ')
                i++;

            if (format[i] == '%')
                count += _write(format[i]);

            if (_validate_char(format[i]) == 0)
            {
                count = _print_invalid_spec(format[i - 1], format[i], count);
            }
            else
            {
                count += _print_spec(format[i], args);
            }
        }
        else
        {
            count += _write(format[i]);
        }

        i++;
    }

    return (count);
}

/**
 * _print_spec - Prints a valid format specifier.
 * @format: The format specifier to print.
 * @args: A list of variadic arguments.
 *
 * Return: The length of the format specifier.
 */
int _print_spec(char format, va_list args)
{
    int i = 0, length = 0;
    spc_dt _types[] = {
        {"c", _print_a_char},
        {"s", _print_a_string},
        {"d", _print_a_integer},
        {"i", _print_a_integer},
        {"b", _print_int_binary},
        {NULL, NULL}
    };

    while (_types[i].specifier)
    {
        if (*_types[i].specifier == format)
            length = _types[i].f(args);

        i++;
    }

    return (length);
}

/**
 * _print_invalid_spec - Prints an invalid format specifier.
 * @prev_format: The previous format specifier before the invalid specifier.
 * @format: The invalid format specifier to print.
 * @count: The current character count before printing invalid specifiers.
 *
 * Return: The updated character count after printing invalid specifiers.
 */
int _print_invalid_spec(char prev_format, char format, int count)
{
    count += _write('%');

    if (prev_format == ' ')
    {
        count += _write(' ');
        count += _write(format);
    }
    else
    {
        count += _write(format);
    }

    return (count);
}

/**
 * _validate_char - Validates a character against a list of valid format specifiers.
 * @_type: The character to compare.
 *
 * Return: 1 if the character is a valid format specifier, 0 otherwise.
 */
int _validate_char(char _type)
{
    char _types[] = {'c', 's', 'd', 'i', 'b', '%'};
    int i = 0;

    while (_types[i])
    {
        if (_types[i] == _type)
            return (1);
        i++;
    }
    return (0);
}

