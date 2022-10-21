#include "main.h"

/**
 * string_length - find the length of a string
 *
 * @str: the string
 * Return: the length of str
 */
int string_length(char *str)
{
	int length = 0;

	if (str != NULL)
	{
		while (*str != '\0')
		{
			length++;
			str++;
		}
	}
	return (length);
}

/**
 * print_string - print a string to standard output
 *
 * @str: the string to print
 * Return: the number of characters printed
 */
int print_string(char *str)
{
	int characters = 0;

	if (str == NULL)
		return (print_string("(null)"));

	while (*str != '\0')
	{
		characters += _putchar(*str);
		str++;
	}
	return (characters);
}

/**
 * print_string_custom - custom print function
 *
 * @str: the string to print
 * Return: the number of characters printed
 */
int print_string_custom(char *str)
{
	int characters = 0;

	if (str == NULL)
		return (print_string("(null)"));

	while (*str)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			characters += print_string("\\x");
			if (*str < 0x10)
				characters += _putchar('0');
			characters += print_number_upper(*str, 16);
		}
		else
			characters += _putchar(*str);
		str++;
	}
	return (characters);
}
