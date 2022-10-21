#include "main.h"

/**
 * get_flags - get the flags for a specifier
 * and mark their status on params struct
 *
 * @s: string to check for flags
 * @params: parameter struct
 * Return: number of flags gotten
 *
 */
int get_flags(char *s, params_t *params)
{
	int i = 0;

	while (s[i])
	{
		switch (s[i])
		{
			case '+':
				params->plus_flag = 1;
				break;
			case ' ':
				params->space_flag = 1;
				break;
			case '#':
				params->hash_flag = 1;
				break;
			case '0':
				params->zero_flag = 1;
				break;
			case '-':
				params->minus_flag = 1;
				break;
			default:
				return (i);
		}
		i++;
	}
	return (i);
}

/**
 * get_specifier_func - select the correct function to print a format
 *
 * @c: the char representing the format
 * Return: pointer to the appropriate function
 */
int (*get_specifier_func(char c))(va_list, params_t *)
{
	spec_t specifiers[] = {
		{'%', print_percent},
		{'c', print_c},
		{'s', print_s},
		{'d', print_d},
		{'i', print_d},
		{'b', print_b},
		{'u', print_u},
		{'o', print_o},
		{'x', print_x},
		{'X', print_X},
		{'p', print_p},
		{'S', print_S},
		{'r', print_r},
		{'R', print_R},
		{0, NULL}
	};
	int i = 0;

	while (specifiers[i].c)
	{
		if (specifiers[i].c == c)
			return (specifiers[i].f);
		i++;
	}
	return (NULL);
}

/**
 * is_digit - check if a character is a digit
 *
 * @c: the character
 * Return: 1 if c is a digit, otherwise 0
 */
int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * get_width - get width parameter and
 * reflect it on the params struct
 *
 * @s: string to check
 * @ap: arguments va_list
 * @params: parameter struct
 * Return: number of characters iterated to find width
 */
int get_width(char *s, va_list ap, params_t *params)
{
	int i = 0, w = 0;

	if (*s == '*')
	{
		w = va_arg(ap, int);
		i++;
	}
	else
	{
		while (is_digit(s[i]))
		{
			w = w * 10 + (s[i] - '0');
			i++;
		}
	}
	params->width = w;
	return (i);
}
