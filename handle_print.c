#include "main.h"

/**
* handle_print - Print an argument based on its type.
*
* This function prints an argument based on its type as specified by the
* format string.
*
* @fmt: The formatted string containing the format specifier.
* @ind: Pointer to the current position in the format string.
* @list: List of arguments.
* @buffer: Buffer array to handle print.
* @flags: Active flags for formatting.
* @width: Width specification.
* @precision: Precision specification.
* @size: Size specifier.
*
* Return: The number of characters printed, or -1 in case of an unknown format.
*/
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
int flags, int width, int precision, int size)
{
int i, unknown_len = 0, printed_chars = -1;

struct {
char fmt;
int (*fn)(va_list, char[], int, int, int, int);
} fmt_types[] = {
{'c', print_char}, {'s', print_string}, {'%', print_percent},
{'i', print_int}, {'d', print_int}, {'b', print_binary},
{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
};

for (i = 0; fmt_types[i].fmt != '\0'; i++) {
if (fmt[*ind] == fmt_types[i].fmt) {
return fmt_types[i].fn(list, buffer, flags, width, precision, size);
}
}

if (fmt_types[i].fmt == '\0') {
if (fmt[*ind] == '\0') {
return -1;
}

// Handle an unknown format character.
unknown_len += write(1, "%%", 1);

// Check if a space was used as padding.
if (fmt[*ind - 1] == ' ') {
unknown_len += write(1, " ", 1);
} else if (width) {
// If width was specified, skip until the next format specifier.
--(*ind);
while (fmt[*ind] != ' ' && fmt[*ind] != '%') {
--(*ind);
}
if (fmt[*ind] == ' ') {
--(*ind);
}
return 1;
}

unknown_len += write(1, &fmt[*ind], 1);
return unknown_len;
}

return printed_chars;
}

