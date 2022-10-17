#include <stddef.h>
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

	if (str != NULL)
	{
		while (*str != '\0')
		{
			characters += _putchar(*str);
			str++;
		}
	}
	return (characters);
}
