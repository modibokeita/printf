#include "main.h"
/**
 * print_octal - Prints an unsigned integer in octal format to stdout.
 * @num: The unsigned integer to be printed.
 *
 * Return: The number of characters printed.
 */
int print_octal(unsigned int num)
{
	int count_num = 0;

	if (num == 0)
	{
		putchar('0');
		count_num++;
	}
	else
	{
		int octal[12];
		int i = 0;

		while (num > 0)
		{
			octal[i++] = num % 8;
			num /= 8;
		}
		while (i > 0)
		{
			putchar(octal[--i] + '0');
			count_num++;
		}
	}
	return (count_num);
}
