#include "main.h"
/**
 * print_int - Prints an integer to stdout.
 * @num: The integer to be printed.
 *
 * Return: The number of characters printed.
 */
int print_int(int num)
{
	int count_num = 0;
	int reversed;

	if (num < 0)
	{
		putchar('-');
		count_num++;
		num = -num;
	}
	if (num == 0)
	{
		putchar('0');
		count_num++;
	}
	else
	{
		reversed = 0;

		while (num > 0)
		{
			reversed = reversed * 10 + num % 10;
			num /= 10;
			count_num++;
		}
		while (reversed > 10)
		{
			putchar(reversed % 10 + '0');
			reversed /= 10;
		}
	}
	return (count_num);

}
