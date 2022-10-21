#include "main.h"

/**
 * print_b - helper function for _printf
 *
 * @ap: arguments va_list
 * @params: parameters struct
 * Return: number of characters printed
 */
int print_b(va_list ap, params_t *params)
{
	int len = 0, inner_width = 0, i = 0;
	unsigned int arg = va_arg(ap, unsigned int);
	char *alt_form_prefix = params->hash_flag ? "0b" : "";

	inner_width += number_digits(arg, 2);

	len += params->zero_flag ? print_string(alt_form_prefix) : 0;
	while (!params->minus_flag && (i < params->width - inner_width))
	{
		len += params->zero_flag ? _putchar('0') : _putchar(' ');
		i++;
	}
	len += !params->zero_flag ? print_string(alt_form_prefix) : 0;
	len += print_number(arg, 2);
	while (params->minus_flag && (i < params->width - inner_width))
	{
		len += _putchar(' ');
		i++;
	}
	return (len);
}

/**
 * print_u - helper function for _printf
 *
 * @ap: arguments va_list
 * @params: parameters struct
 * Return: number of characters printed
 */
int print_u(va_list ap, params_t *params)
{
	int len = 0, inner_width = 0, i = 0;
	unsigned int arg = va_arg(ap, unsigned int);

	inner_width += number_digits(arg, 10);

	while (!params->minus_flag && (i < params->width - inner_width))
	{
		len += params->zero_flag ? _putchar('0') : _putchar(' ');
		i++;
	}
	len += print_number(arg, 10);
	while (params->minus_flag && (i < params->width - inner_width))
	{
		len += _putchar(' ');
		i++;
	}
	return (len);
}

/**
 * print_o - helper function for _printf
 *
 * @ap: arguments va_list
 * @params: parameters struct
 * Return: number of characters printed
 */
int print_o(va_list ap, params_t *params)
{
	int len = 0, inner_width = 0, i = 0;
	unsigned int arg = va_arg(ap, unsigned int);
	char *alt_form_prefix = params->hash_flag && arg > 0 ? "0" : "";

	inner_width += number_digits(arg, 8);

	len += params->zero_flag ? print_string(alt_form_prefix) : 0;
	while (!params->minus_flag && (i < params->width - inner_width))
	{
		len += params->zero_flag ? _putchar('0') : _putchar(' ');
		i++;
	}
	len += !params->zero_flag ? print_string(alt_form_prefix) : 0;
	len += print_number(arg, 8);
	while (params->minus_flag && (i < params->width - inner_width))
	{
		len += _putchar(' ');
		i++;
	}
	return (len);
}

/**
 * print_x - helper function for _printf
 *
 * @ap: arguments va_list
 * @params: parameters struct
 * Return: number of characters printed
 */
int print_x(va_list ap, params_t *params)
{
	int len = 0, inner_width = 0, i = 0;
	unsigned int arg = va_arg(ap, unsigned int);
	char *alt_form_prefix = params->hash_flag ? "0x" : "";

	inner_width += number_digits(arg, 16);

	len += params->zero_flag ? print_string(alt_form_prefix) : 0;
	while (!params->minus_flag && (i < params->width - inner_width))
	{
		len += params->zero_flag ? _putchar('0') : _putchar(' ');
		i++;
	}
	len += !params->zero_flag ? print_string(alt_form_prefix) : 0;
	len += print_number(arg, 16);
	while (params->minus_flag && (i < params->width - inner_width))
	{
		len += _putchar(' ');
		i++;
	}
	return (len);
}

/**
 * print_X - helper function for _printf
 *
 * @ap: arguments va_list
 * @params: parameters struct
 * Return: number of characters printed
 */
int print_X(va_list ap, params_t *params)
{
	int len = 0, inner_width = 0, i = 0;
	unsigned int arg = va_arg(ap, unsigned int);
	char *alt_form_prefix = params->hash_flag ? "0X" : "";

	inner_width += number_digits(arg, 16);

	len += params->zero_flag ? print_string(alt_form_prefix) : 0;
	while (!params->minus_flag && (i < params->width - inner_width))
	{
		len += params->zero_flag ? _putchar('0') : _putchar(' ');
		i++;
	}
	len += !params->zero_flag ? print_string(alt_form_prefix) : 0;
	len += print_number_upper(arg, 16);
	while (params->minus_flag && (i < params->width - inner_width))
	{
		len += _putchar(' ');
		i++;
	}
	return (len);
}
