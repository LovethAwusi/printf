#include "main.h"

int _isdigit(int c) { return c >= '0' && c <= '9'; }

int _strlen(char *s) {
    int i = 0;
    while (*s++) i++;
    return i;
}

int print_number(char *str, params_t *params) {
    unsigned int i = _strlen(str), n = 0;
    int neg = (!params->unsign && *str == '-');
    if (!params->precision && *str == '0' && !str[1]) str = "";
    if (neg) { str++; i--; }
    if (params->precision != UINT_MAX) while (i++ < params->precision) *--str = '0';
    if (neg) *--str = '-';
    if (!params->minus_flag) return print_number_right_shift(str, params);
    return print_number_left_shift(str, params);
}

int print_number_right_shift(char *str, params_t *params) {
    unsigned int n = 0, neg, i = _strlen(str);
    char pad_char = (params->zero_flag && !params->minus_flag) ? '0' : ' ';
    neg = (!params->unsign && *str == '-');
    if (neg && i < params->width && pad_char == '0' && !params->minus_flag) str++;
    else neg = 0;
    if ((params->plus_flag && !neg) || (!params->plus_flag && params->space_flag && !neg)) i++;
    if (neg && pad_char == '0') n += _putchar('-');
    if (params->plus_flag && !neg && pad_char == '0' && !params->unsign) n += _putchar('+');
    else if (!params->plus_flag && params->space_flag && !neg && !params->unsign && params->zero_flag) n += _putchar(' ');
    while (i++ < params->width) n += _putchar(pad_char);
    if (neg && pad_char == ' ') n += _putchar('-');
    if (params->plus_flag && !neg && pad_char == ' ' && !params->unsign) n += _putchar('+');
    return n += _puts(str);
}

int print_number_left_shift(char *str, params_t *params) {
    unsigned int n = 0, neg, i = _strlen(str);
    char pad_char = (params->zero_flag && !params->minus_flag) ? '0' : ' ';
    neg = (!params->unsign && *str == '-');
    if (neg && i < params->width && pad_char == '0' && !params->minus_flag) str++;
    else neg = 0;
    if (params->plus_flag && !neg) n += _putchar('+'), i++;
    else if (params->space_flag && !neg) n += _putchar(' '), i++;
    n += _puts(str);
    while (i++ < params->width) n += _putchar(pad_char);
    return n;
}

