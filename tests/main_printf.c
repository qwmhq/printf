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
	int count;

	count = _printf("testing %%...\n");
	printf("print count: %d\n", count);

	count = _printf("my char is %c\n", c);
	printf("print count: %d\n", count);

	count = _printf("my string is %s\n", s);
	printf("print count: %d\n", count);

	s = NULL;
	count = _printf("printing null string: %s\n", s);
	printf("print count: %d\n", count);
	return (0);
}
