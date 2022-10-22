#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_string(char *str);
int print_string_custom(char *str);
int print_string_reverse(char *str);
int print_string_rot13(char *str);
int string_length(char *str);
int number_digits(unsigned long n, int b);
int print_number(unsigned long, int base);
int print_number_upper(unsigned long num, int base);
int print_decimal(int n);

/**
 * struct params - parameters struct
 *
 * @plus_flag: + flag
 * @space_flag: ' ' flag
 * @hash_flag: # flag
 * @zero_flag: 0 flag
 * @minus_flag: - flag
 * @width: width
 */
typedef struct params
{
	char plus_flag;
	char space_flag;
	char hash_flag;
	char zero_flag;
	char minus_flag;
	int width;
} params_t;

/**
 * struct specifier - format struct
 *
 * @c: format character
 * @f: format function
 */
typedef struct specifier
{
	char c;
	int (*f)(va_list, params_t *);
} spec_t;

int print_percent(va_list ap, params_t *params);
int print_c(va_list ap, params_t *params);
int print_s(va_list ap, params_t *params);
int print_d(va_list ap, params_t *params);
int print_b(va_list ap, params_t *params);
int print_u(va_list ap, params_t *params);
int print_o(va_list ap, params_t *params);
int print_x(va_list ap, params_t *params);
int print_X(va_list ap, params_t *params);
int print_S(va_list ap, params_t *params);
int print_p(va_list ap, params_t *params);
int print_r(va_list ap, params_t *params);
int print_R(va_list ap, params_t *params);

int is_digit(char c);
int get_flags(char *s, params_t *params);
int get_width(char *s, va_list ap, params_t *params);
int (*get_specifier_func(char c))(va_list, params_t *);

params_t *init_params(void);
void free_params(params_t *params);

#endif
