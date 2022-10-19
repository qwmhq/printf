#include "main.h"

/**
 * print_b - helper function for _printf
 *
 * @ap: arguments va_list
 * Return: number of characters printed
 */
int print_b(va_list ap)
{
	return (print_number(va_arg(ap, unsigned int), 2));
}
