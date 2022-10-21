#include "main.h"

/**
 * number_digits - find the number of digits of a number in a particular base
 *
 * @n: the number
 * @b: the base in which to find the number of digits
 * Return: the number of digits to n has in base b
 */
int number_digits(unsigned long n, int b)
{
	unsigned int digits = 0;

	if (n == 0)
		return (1);

	while (n > 0)
	{
		digits++;
		n /= b;
	}
	return (digits);
}

/**
 * print_number - print a number in number in a particular base
 *
 * @num: the number to print
 * @base: the base in which to print the number
 * Return: the number of characters printed
 */
int print_number(unsigned long num, int base)
{
	char *d = "0123456789abcdef";
	int len = 0;

	if (num / base)
	{
		len += print_number(num / base, base);
	}

	len += _putchar(d[num % base]);

	return (len);
}

/**
 * print_number_upper - print a number in number in a particular base
 * (bases that use letters are printed in upper case)
 *
 * @num: the number to print
 * @base: the base in which to print the number
 * Return: the number of characters printed
 */
int print_number_upper(unsigned long num, int base)
{
	char *d = "0123456789ABCDEF";
	int len = 0;

	if (num / base)
	{
		len += print_number_upper(num / base, base);
	}

	len += _putchar(d[num % base]);

	return (len);
}
