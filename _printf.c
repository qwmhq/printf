#include "main.h"

/**
 * print_c - helper function for _printf
 *
 * @ap: arguments va_list
 * Return: number of characters printed
 */
int print_c(va_list ap)
{
	return (_putchar(va_arg(ap, int)));
}

/**
 * print_s - helper function for _printf
 *
 * @ap: arguments va_list
 * Return: number of characters printed
 */
int print_s(va_list ap)
{
	return (print_string(va_arg(ap, char *)));
}

/**
 * print_d - helper function for _printf
 *
 * @ap: arguments va_list
 * Return: number of characters printed
 */
int print_d(va_list ap)
{
	return (print_decimal(va_arg(ap, int)));
}

/**
 * get_format_func - select the correct function to print a format
 *
 * @c: the char representing the format
 * Return: pointer to the appropriate function
 */
int (*get_format_func(char c))(va_list)
{
	format_t ff[] = {
		{'c', print_c},
		{'s', print_s},
		{'d', print_d},
		{'i', print_d},
		{0, NULL}
	};
	int i = 0;

	while (ff[i].c != 0)
	{
		if (ff[i].c == c)
			return (ff[i].f);
		i++;
	}
	return (NULL);
}

/**
 * _printf - print a formatted string
 *
 * @format: the format of the string
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, len = 0;
	va_list ap;

	va_start(ap, format);

	if (format == NULL || (format[i] == '%' && format[i + 1] == '\0'))
		return (-1);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			int (*format_func)(va_list);

			if (format[i + 1] == '%')
			{
				len += _putchar('%');
				i += 2;
				continue;
			}
			format_func = get_format_func(format[i + 1]);
			if (format_func != NULL)
			{
				len += format_func(ap);
				i += 2;
				continue;
			}
		}

		len += _putchar(format[i]);
		i++;
	}

	va_end(ap);
	return (len);
}
