#include "main.h"

/**
 * _puts - Print a string with a newline.
 * @str: The string to print.
 *
 * Return: Number of characters printed, including the newline.
 */
int _puts(char *str)
{
	int count = 0; // Initialize a count to keep track of characters printed.

	while (*str)
	{
		_putchar(*str++); // Print the current character.
		count++;
	}
	return (count); // Return the total count of characters printed.
}

/**
 * _putchar - Write the character c to stdout.
 * @c: The character to write to stdout.
 *
 * Return: On success, return 1. On error, return -1.
 */
int _putchar(int c)
{
	static int i = 0; // Initialize a static index to keep track of the buffer position.
	static char buf[OUTPUT_BUF_SIZE]; // Initialize a static buffer to store characters.

	if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, i); // Flush the buffer to stdout when it's full or a flush signal is received.
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c; // Store the character in the buffer.

	return (1); // Return 1 to indicate success.
}
