#ifndef _PRINTF_H_
#define _PRINTF_H_

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define FIELD_BUF_SIZE 50

#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/**
 * struct parameters - Structure for formatting parameters
 *
 * @unsign: Flag for unsigned value
 * @plus_flag: Plus flag specified
 * @space_flag: Space flag specified
 * @hashtag_flag: Hashtag flag specified
 * @zero_flag: Zero flag specified
 * @minus_flag: Minus flag specified
 * @width: Field width specified
 * @precision: Field precision specified
 * @h_modifier: H modifier specified
 * @l_modifier: L modifier specified
 */
typedef struct parameters
{
    unsigned int unsign : 1;
    unsigned int plus_flag : 1;
    unsigned int space_flag : 1;
    unsigned int hashtag_flag : 1;
    unsigned int zero_flag : 1;
    unsigned int minus_flag : 1;
    unsigned int width;
    unsigned int precision;
    unsigned int h_modifier : 1;
    unsigned int l_modifier : 1;
} params_t;

/**
 * struct specifier - Structure for format specifiers and associated functions
 *
 * @specifier: Format specifier
 * @f: Associated function
 */
typedef struct specifier
{
    char *specifier;
    int (*f)(va_list, params_t *);
} specifier_t;

/* _prinf.c module */
int _printf(const char *format, ...);

/* print_functions.c module */
int print_char(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);
int print_S(va_list ap, params_t *params);

/* number.c module */
char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list ap, params_t *params);
int print_address(va_list ap, params_t *params);

/* convert_number.c module */
int print_hex(va_list ap, params_t *params);
int print_HEX(va_list ap, params_t *params);
int print_binary(va_list ap, params_t *params);
int print_octal(va_list ap, params_t *params);

/* specifier.c module */
int (*get_specifier(char *s))(va_list ap, params_t *params);
int get_print_func(char *s, va_list ap, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list ap);

/* simple_printers.c module */
int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list ap, params_t *params);
int print_rot13(va_list ap, params_t *params);

/* print_number.c module */
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);

/* params.c module */
void init_params(params_t *params, va_list ap);

/* string_fields.c modoule */
char *get_precision(char *p, params_t *params, va_list ap);

#endif /* _PRINTF_H_ */

