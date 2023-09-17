#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function
 * @format: The format string
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;
    char c;

    va_start(args, format);

    while (format && format[printed_chars])
    {
        if (format[printed_chars] != '%')
        {
            write(1, &format[printed_chars], 1);
            printed_chars++;
            continue;
        }

        printed_chars++;
        c = format[printed_chars];
        switch (c)
        {
            case 'c':
                putchar(va_arg(args, int));
                break;
            case 's':
                write(1, va_arg(args, char *), 1);
                break;
            case '%':
                putchar('%');
                break;
            default:
                putchar('%');
                putchar(c);
                break;
        }
        printed_chars++;
    }

    va_end(args);
    return (printed_chars);
}

int main()
{
    int n;
    char *str = "Hello, World!";

    n = _printf("Printing a character: %c\n", 'A');
    _printf("Printing a string: %s\n", str);
    _printf("Printing a percent sign: %%\n");
    _printf("Unknown specifier: %q\n");

    return (0);
}

