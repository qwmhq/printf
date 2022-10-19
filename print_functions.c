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

/**
 * print_u - helper function for _printf
 *
 * @ap: arguments va_list
 * Return: number of characters printed
 */
int print_u(va_list ap)
{
	return (print_number(va_arg(ap, unsigned int), 10));
}

/**
 * print_o - helper function for _printf
 *
 * @ap: arguments va_list
 * Return: number of characters printed
 */
int print_o(va_list ap)
{
	return (print_number(va_arg(ap, unsigned int), 8));
}

/**
 * print_x - helper function for _printf
 *
 * @ap: arguments va_list
 * Return: number of characters printed
 */
int print_x(va_list ap)
{
	return (print_number(va_arg(ap, unsigned int), 16));
}

/**
 * print_X - helper function for _printf
 *
 * @ap: arguments va_list
 * Return: number of characters printed
 */
int print_X(va_list ap)
{
	return (print_number_upper(va_arg(ap, unsigned int), 16));
}
