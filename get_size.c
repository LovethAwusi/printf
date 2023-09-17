#include "main.h"

/**
* get_size - Calculate the size to cast the argument.
*
* This function calculates the size to cast the argument based on the format string.
*
* @format: The formatted string in which to find the argument size.
* @i: Pointer to the current position in the format string.
*
* Return: The calculated argument size.
*/
int get_size(const char *format, int *i)
{
int curr_i = *i + 1;
int size = 0;

if (format[curr_i] == 'l')
{
size = S_LONG;
}
else if (format[curr_i] == 'h')
{
size = S_SHORT;
}

if (size == 0)
{
*i = curr_i - 1;
}
else
{
*i = curr_i;
}

return size;
}

