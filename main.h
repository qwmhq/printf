#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_string(char *str);
int string_length(char *str);
int number_digits(int n, int b);
int print_number(unsigned long num, int base);
int print_decimal(int n);

typedef struct format_struct
{
	char character;
	int (* print_function)(va_list);
} format_t;

#endif
