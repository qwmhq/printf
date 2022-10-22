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

/**
 * print_string_reverse - print a string in reverse
 *
 * @str: the string to print
 * Return: number of characters printed
 */
int print_string_reverse(char *str)
{
	int characters = 0, str_len = string_length(str);

	if (str == NULL)
		return (print_string("(null)"));

	while (str_len)
	{
		characters += _putchar(str[str_len - 1]);
		str_len--;
	}
	return (characters);
}

/**
 * print_string_rot13 - print a string using rot13 encryption
 *
 * @str: the string to print
 * Return: number of characters printed
 */
int print_string_rot13(char *str)
{
	int characters = 0, i, j;
	char *letters =
		"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *encoded_letters =
		"nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	if (str == NULL)
		return (print_string("(null)"));

	for (i = 0; i < string_length(str); i++)
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
		{
			for (j = 0; j < string_length(letters); j++)
			{
				if (str[i] == letters[j])
				{
					characters += _putchar(encoded_letters[j]);
					break;
				}
			}
		}
		else
			characters += _putchar(str[i]);
	}
	return (characters);
}
