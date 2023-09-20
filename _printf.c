#include "main.h"

int print_int(int num);
int print_octal(unsigned int num);
int print_hexadecimal(unsigned int num, int uppercase);
int print_uint(unsigned int num);

/**
 * _printf - produces output according to a format.
 * @format: string format
 * @...: other arguments
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list list_of_args;
	int chara_print = 0;
	int i, j;

	va_start(list_of_args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;

			switch (format[i])
			{
				case 'c':
					{
						char c = va_arg(list_of_args, int);

						putchar(c);
						chara_print++;
						break;
					}
				case 's':
					{

						char *str = va_arg(list_of_args, char*);

						fputs(str, stdout);
						chara_print += strlen(str);
						break;
					}
				case 'i':
				case 'd':
					{
						int num = va_arg(list_of_args, int);

						chara_print += print_int(num);
						break;
					}
				case 'o':
					{
						unsigned int num = va_arg(list_of_args, unsigned int);

						chara_print += print_octal(num);
						break;
					}
				case 'x':
				case 'X':
					{
						unsigned int num = va_arg(list_of_args, unsigned int);

						chara_print += print_hexadecimal(num, format[i] == 'X');
						break;
					}
				case 'u':
					{
						unsigned int num = va_arg(list_of_args, unsigned int);

						chara_print += print_uint(num);
						break;
					}
				case 'p':
					{
						void *ptr = va_arg(list_of_args, void*);

					if (ptr == NULL)
					{
						fputs("(nil)", stdout);
						chara_print += 5;
					}
					else
					{
						unsigned long address = (unsigned long)ptr;
						char buffer[sizeof(unsigned long) * 2 + 3];

						snprintf(buffer, sizeof(buffer), "0x%lx", address);
						fputs(buffer, stdout);
						chara_print += strlen(buffer);
					}
					break;
					}
				case 'f':
					{
						double num = va_arg(list_of_args, double);

						fprintf(stdout, "%f", num);
						chara_print++;
						break;
					}
				case 'n':
					break;
				case 'b':
					{
						unsigned int num = va_arg(list_of_args, unsigned int);
						int bits[sizeof(unsigned int) * 8];
						int index = 0;

					while (num > 0)
					{
						bits[index] = num % 2;
						num /= 2;
						index++;
					}
					for (j = index - 1; j >= 0; j--)
					{
						fprintf(stdout, "%d", bits[j]);
						chara_print++;
					}
					break;
					}
				case '%':
					{
						putchar('%');
						chara_print++;
						break;
					}
				default:
					{
						putchar('%');
						chara_print++;
						putchar(format[i]);
						chara_print++;
						break;
					}
			}
		}
		else
		{
			putchar(format[i]);
			chara_print++;
		}
	}
	va_end(list_of_args);
	return (chara_print);
}

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
		while (reversed > 0)
		{
			putchar(reversed % 10 + '0');
			reversed /= 10;
		}
	}
	return (count_num);
}

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
