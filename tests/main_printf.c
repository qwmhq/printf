#include <stdio.h>
#include "../main.h"

/**
 * main - main function
 *
 * Return: always 0
 *
 */
int main(void)
{
	char c = 'a';
	char *s = "hello";
	int my_int = 123;
	int count;

	count = _printf("testing %%...\n");
	printf("print count: %d\n", count);

	count = _printf("hello world!\n");
	printf("print count: %d\n", count);
	_printf("print count: %d\n", count);

	count = _printf("my char is %5c\n", c);
	_printf("print count: %d\n", count);

	count = _printf("my string is %7s\n", s);
	_printf("print count: %d\n", count);

	s = NULL;
	count = _printf("printing null string: %s\n", s);
	_printf("print count: %d\n", count);

	count = _printf("my int is %+05d\n", my_int);
	_printf("print count: %d\n", count);

	count = _printf("my int is % i\n", my_int);
	_printf("print count: %d\n", count);

	my_int = -1;
	count = _printf("my int is %05d\n", my_int);
	_printf("print count: %d\n", count);

	count = _printf("my int is %i\n", my_int);
	_printf("print count: %d\n", count);

	my_int = 11;
	count = _printf("testing binary: %#8b\n", my_int);
	_printf("print count: %d\n", count);

	my_int = 0x123abc;
	count = _printf("testing hexadecimal: %#x\n", my_int);
	_printf("print count: %d\n", count);

	count = _printf("testing hexadecimal upper: %#X\n", my_int);
	_printf("print count: %d\n", count);

	my_int = 02732;
	count = _printf("testing octal: %#o\n", my_int);
	_printf("print count: %d\n", count);

	my_int = 00;
	count = _printf("testing octal: %#o\n", my_int);
	_printf("print count: %d\n", count);

	my_int = 12345;
	count = _printf("testing unsigned: %u\n", my_int);
	_printf("print count: %d\n", count);
	

	return (0);
}
