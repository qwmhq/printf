#include "../main.h"
#include <stdio.h>

/**
 * main - main function
 * Return: always 0
 */
int main(void)
{
	int num, digits;

	num = 12345;

	digits = print_number(num, 10);
	printf("\nnumber of digits in 12345 (base 10): %d\n", digits);
	digits = print_number(num, 16);
	printf("\nnumber of digits in 12345 (converted to base 16): %d\n", digits);
	digits = print_number(num, 2);
	printf("\nnumber of digits in 12345 (converted to base 2): %d\n", digits);

	num = 0x123abc;
	digits = print_number(num, 16);
	printf("\nnumber of digits in 123abc (base 16): %d\n", digits);

	num = 0;
	digits = print_number(num, 10);
	printf("number of digits in 0 (base 10): %d\n", digits);
	digits = print_number(num, 16);
	printf("number of digits in 0 (base 16): %d\n", digits);

	num = -12345;
	printf("number of digits in -12345 (base 10): %d\n", number_digits(num, 10));
	
	num = -0x123abc;
	printf("number of digits in -123abc (base 16): %d\n", number_digits(num, 16));

	return (0);
}
