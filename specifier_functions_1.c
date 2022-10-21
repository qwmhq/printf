#include "main.h"

/**
 * print_percent - helper function for _printf
 *
 * @ap: arguments va_list
 * @params: parameter struct
 * Return: number of characters printed
 */
int print_percent(va_list ap, params_t *params)
{
	(void)ap;
	(void)params;
	return (_putchar('%'));
}

/**
 * print_c - helper function for _printf
 *
 * @ap: arguments va_list
 * @params: parameter struct
 * Return: number of characters printed
 */
int print_c(va_list ap, params_t *params)
{
	int len = 0, i = 0;
	int arg = va_arg(ap, int);

	while (!params->minus_flag && (i < (params->width - 1)))
	{
		len += _putchar(' ');
		i++;
	}

	len += _putchar(arg);

	while (params->minus_flag && i < (params->width - 1))
	{
		len += _putchar(' ');
		i++;
	}
	return (len);
}

/**
 * print_s - helper function for _printf
 *
 * @ap: arguments va_list
 * @params: parameter struct
 * Return: number of characters printed
 */
int print_s(va_list ap, params_t *params)
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

	len += print_string(arg);

	while (params->minus_flag && i < (params->width - len_arg))
	{
		len += _putchar(' ');
		i++;
	}

	return (len);
}

/**
 * print_S - helper function for _printf
 *
 * @ap: arguments va_list
 * @params: parameters struct
 * Return: number of characters printed
 */
int print_S(va_list ap, params_t *params)
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

	len += print_string_custom(arg);

	while (params->minus_flag && i < (params->width - len_arg))
	{
		len += _putchar(' ');
		i++;
	}

	return (len);
}

/**
 * print_d - helper function for _printf
 *
 * @ap: arguments va_list
 * @params: parameters struct
 * Return: number of characters printed
 */
int print_d(va_list ap, params_t *params)
{
	int len = 0, inner_width = 0, i = 0;
	int arg = va_arg(ap, int);
	char sign;

	if (arg < 0)
		sign = '-';
	else if (params->space_flag)
		sign = ' ';
	else if (params->plus_flag)
		sign = '+';
	else
		sign = 0;

	if (sign)
		inner_width++;
	inner_width += number_digits(arg, 10);

	arg = arg < 0 ? -arg : arg;

	len += params->zero_flag ? _putchar(sign) : 0;
	while (!params->minus_flag && (i < params->width - inner_width))
	{
		len += params->zero_flag ? _putchar('0') : _putchar(' ');
		i++;
	}
	len += !params->zero_flag ? _putchar(sign) : 0;
	len += print_number(arg, 10);
	while (params->minus_flag && (i < params->width - inner_width))
	{
		len += _putchar(' ');
		i++;
	}
	return (len);
}
