#include "../main.h"
#include <stdio.h>

/**
 * main - main function
 * Return: always 0
 */
int main(void)
{
	int length;
	int characters;
	char *string;

	string = "hello world!";
	length = string_length(string);
	
	printf("Length of \"hello world!\": %d\n", length);
	characters = print_string(string);
	printf("\nno of characters printed by print_string for \" hello world!\": %d\n\n", characters);

	string = NULL;
	length = string_length(string);

	printf("Length of null string: %d\n", length);
	characters = print_string(string);
	printf("\nno of characters printed by print_string for null string: %d\n", characters);

	return (0);
}
