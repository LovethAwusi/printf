#include "main.h"

/**
* print_hex - prints the  unsigned hex in lowercase
* @ap: argument pointer
* @params: parameters struct
*
* Return: This is the bytes printed
*/
int print_hex(va_list ap, params_t *params)
{
unsigned long l;
int c = 0;
char *str;

if (params->l_modifier)
l = (unsigned long)va_arg(ap, unsigned long);
else if (params->h_modifier)
l = (unsigned short int)va_arg(ap, unsigned int);
else
l = (unsigned int)va_arg(ap, unsigned int);

str = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
if (params->hashtag_flag && l)
{
*--str = 'x';
*--str = '0';
}
params->unsign = 1;
return (c += print_number(str, params));
}

/**
* print_HEX - prints the unsigned hex no in uppercase
* @ap: argument pointer
* @params: parameters struct
*
* Return: This is the bytes printed
*/
int print_HEX(va_list ap, params_t *params)
{
unsigned long l;
int c = 0;
char *str;

if (params->l_modifier)
l = (unsigned long)va_arg(ap, unsigned long);
else if (params->h_modifier)
l = (unsigned short int)va_arg(ap, unsigned int);
else
l = (unsigned int)va_arg(ap, unsigned int);

str = convert(l, 16, CONVERT_UNSIGNED, params);
if (params->hashtag_flag && l)
{
*--str = 'X';
*--str = '0';
}
params->unsign = 1;
return (c += print_number(str, params));
}
/**
* print_binary - This prints the  unsigned binary no
* @ap: argument pointer
* @params: parameters struct
*
* Return: This is the bytes printed
*/
int print_binary(va_list ap, params_t *params)
{
unsigned int n = va_arg(ap, unsigned int);
char *str = convert(n, 2, CONVERT_UNSIGNED, params);
int c = 0;

if (params->hashtag_flag && n)
*--str = '0';
params->unsign = 1;
return (c += print_number(str, params));
}

/**
* print_octal - This prints unsigned octal no
* @ap: Argument pointer
* @params: parameters struct
*
* Return:This is  bytes printed
*/
int print_octal(va_list ap, params_t *params)
{
unsigned long l;
char *str;
int c = 0;

if (params->l_modifier)
l = (unsigned long)va_arg(ap, unsigned long);
else if (params->h_modifier)
l = (unsigned short int)va_arg(ap, unsigned int);
else
l = (unsigned int)va_arg(ap, unsigned int);
str = convert(l, 8, CONVERT_UNSIGNED, params);

if (params->hashtag_flag && l)
*--str = '0';
params->unsign = 1;
return (c += print_number(str, params));
}
