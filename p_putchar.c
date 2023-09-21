#include "main.h"

/**
* _puts - prints the string on a new line
* @str: this is the string to print
*
* Return:( str-a)
*/
int _puts(char *str)
{
char *a = str;/*declaration of variables*/

while (*str)
_putchar(*str++);
return (str - a);
}

/**
* _putchar - writes char c  to stdout
* @c: char to print
*
* Return: On success 1 should be returned.
* -1 is returned when error occurs and error is set appropriately.
*/
int _putchar(int c)
{
static int i;
static char buf[OUTPUT_BUF_SIZE];

if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
{
write(1, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}
