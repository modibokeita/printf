#include "main.h"
/**
 * print_hexadecimal - Prints an unsigned integer
 * @num: The unsigned integer to be printed.
 * @uppercase: 1 for uppercase letters (A-F), 0 for lowercase (a-f).
 *
 * Return: The number of characters printed.
 */
int print_hexadecimal(unsigned int num, int uppercase)
{
	int count_num = 0;
	char hex_chars[] = "0123456789abcdef";

	if (num == 0)
	{
		putchar('0');
		count_num++;
	}
	else
	{
		char hex[12];
		int i = 0;

		while (num > 0)
		{
			hex[i++] = hex_chars[num % 16];
			num /= 16;
		}
		while (i > 0)
		{
			char c = hex[--i];

			if (uppercase)
				c = toupper(c);
			putchar(c);
			count_num++;
		}
	}
	return (count_num);
}
