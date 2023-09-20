#include "main.h"

/**
 * print_uint - Prints an unsigned integer to stdout.
 * @num: The unsigned integer to be printed.
 *
 * Return: The number of characters printed.
 */
int print_uint(unsigned int num)
{
	int count_num = 0;

	if (num == 0)
	{
		putchar('0');
		count_num++;
	}
	else
	{
		int reversed = 0;

		while (num > 0)
		{
			reversed = reversed * 10 + num % 10;
			num /= 10;
			count_num++;
		}
		while (reversed > 0)
		{
			putchar(reversed % 10 + '0');
			reversed /= 10;
		}
	}
	return (count_num);
}
