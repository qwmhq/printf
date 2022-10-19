#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_string(char *str);
int string_length(char *str);
int number_digits(int n, int b);
int print_number(unsigned int num, int base);
int print_number_upper(unsigned int num, int base);
int print_decimal(int n);

/**
 * struct format_struct - format struct
 *
 * @c: format character
 * @f: format function
 */
typedef struct format_struct
{
	char c;
	int (*f)(va_list);
} format_t;

int print_c(va_list ap);
int print_s(va_list ap);
int print_b(va_list ap);
int print_u(va_list ap);
int print_o(va_list ap);
int print_x(va_list ap);
int print_X(va_list ap);

#endif
