#ifndef MAIN_H
#define MAIN_H

/* Header files */
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * struct CharPrint - Specifies a format specifier and its associated printing function.
 * @c: The format specifier.
 * @pr_Fntn: A function pointer to the printing function.
 */
typedef struct CharPrint
{
    char *c;
    int (*pr_Fntn)(va_list arg);
} PrintInstruction;

/* Prototypes */
int _putchar(char c); // Write a single character to the standard output.
int _printf(const char *format, ...); // Custom printf function.
int printS(va_list arg); // Print a string.
int printDec(va_list arg); // Print a decimal integer.
int printUn(va_list arg); // Print an unsigned integer.
int printB(va_list arg); // Print a binary number.
int printC(va_list arg); // Print a character.
int printP(va_list arg __attribute__((unused))); // Placeholder function (unused).
int printDigit(long int b, long int d); // Helper function for printing digits.
int printDigitUn(unsigned int b, long int d); // Helper function for printing unsigned digits.

#endif
