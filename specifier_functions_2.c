#include "main.h"

/**
 * print_p - helper function for _printf
 *
 * @ap: arguments va_list
 * @params: parameters struct
 * Return: number of characters printed
 */
int print_p(va_list ap, params_t *params)
{
	int len = 0, inner_width = 0, i = 0;
	void *arg = va_arg(ap, void *);
	unsigned long n = (unsigned long)arg;
	char *alt_form_prefix = "0x";

	inner_width += number_digits(n, 16);

	len += params->zero_flag ? print_string(alt_form_prefix) : 0;
	while (!params->minus_flag && (i < params->width - inner_width))
	{
		len += params->zero_flag ? _putchar('0') : _putchar(' ');
		i++;
	}
	len += !params->zero_flag ? print_string(alt_form_prefix) : 0;
	len += print_number(n, 16);
	while (params->minus_flag && (i < params->width - inner_width))
	{
		len += _putchar(' ');
		i++;
	}
	return (len);
}

/**
 * print_r - helper function for _printf
 *
 * @ap: arguments va_list
 * @params: parameters struct
 * Return: number of characters printed
 */
int print_r(va_list ap, params_t *params)
{
	int len = 0, i = 0;
	char *arg;
	int len_arg;

	arg = va_arg(ap, char *);
	len_arg = string_length(arg);

	while (!params->minus_flag && (i < (params->width - len_arg)))
	{
		len += _putchar(' ');
		i++;
	}

	len += print_string_reverse(arg);

	while (params->minus_flag && i < (params->width - len_arg))
	{
		len += _putchar(' ');
		i++;
	}

	return (len);
}

/**
 * print_R - helper function for _printf
 *
 * @ap: arguments va_list
 * @params: parameters struct
 * Return: number of characters printed
 */
int print_R(va_list ap, params_t *params)
{
	int len = 0, i = 0;
	char *arg;
	int len_arg;

	arg = va_arg(ap, char *);
	len_arg = string_length(arg);

	while (!params->minus_flag && (i < (params->width - len_arg)))
	{
		len += _putchar(' ');
		i++;
	}

	len += print_string_rot13(arg);

	while (params->minus_flag && i < (params->width - len_arg))
	{
		len += _putchar(' ');
		i++;
	}

	return (len);
}
