#include "main.h"

/**
 * print_string_slice - print a slice of a string
 *
 * @str: string
 * @a: start index
 * @b: end index
 * Return: number of characters printed
 */
int print_string_slice(char *str, int a, int b)
{
	int len = b - a;

	while (a < b)
	{
		_putchar(str[a]);
		a++;
	}
	return (len);
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
	int len = 0, i = 0, start_index;
	va_list ap;
	char *p = (char *)format;

	va_start(ap, format);

	if (format == NULL || (format[i] == '%' && format[i + 1] == '\0'))
		return (-1);

	while (format[i])
	{
		if (format[i] == '%')
		{
			int (*specifier_func)(va_list, params_t *);
			params_t *params = init_params();

			start_index = i;
			i++;
			i += get_flags((p + i), params);
			i += get_width((p + i), ap, params);

			specifier_func = get_specifier_func(*(p + i));

			if (specifier_func != NULL)
			{
				len += specifier_func(ap, params);
				i++;
			}
			else
				len += print_string_slice(p, start_index, i);
			free_params(params);
			continue;
		}
		len += _putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (len);
}
