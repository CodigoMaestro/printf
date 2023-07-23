#include "main.h"
#include <string.h>
#include <stdio.h>

int print_char(char c);
int print_string(const char *str);
int print_integer(int num);

/**
 * print_int - prints integer
 * @args: argument to print
 * Return: number of characters printed
 */

int print_int(va_list args)
{
	int n = va_arg(args, int);
	int num, last = n % 10, digit, exp = 1;
	int  i = 1;

	n = n / 10;
	num = n;

	if (last < 0)
	{
		my_putchar('-');
		num = -num;
		n = -n;
		last = -last;
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = n;
		while (exp > 0)
		{
			digit = num / exp;
			my_putchar(digit + '0');
			num = num - (digit * exp);
			exp = exp / 10;
			i++;
		}
	}
	my_putchar(last + '0');

	return (i);
}

/**
 * print_dec - prints decimal
 * @args: argument to print
 * Return: number of characters printed
 */

int print_dec(va_list args)
{
	int n = va_arg(args, int);
	int num, last = n % 10, digit;
	int  i = 1;
	int exp = 1;

	n = n / 10;
	num = n;

	if (last < 0)
	{
		my_putchar('-');
		num = -num;
		n = -n;
		last = -last;
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = n;
		while (exp > 0)
		{
			digit = num / exp;
			my_putchar(digit + '0');
			num = num - (digit * exp);
			exp = exp / 10;
			i++;
		}
	}
	my_putchar(last + '0');

	return (i);
}

/**
 * process_format_specifier - entry point
 * @format: char
 * @args: va_list
 * @count: int
 * Return: int
 */

int process_format_specifier(char format, va_list args, int count)
{
	switch (format)
	{
		case 'c':
			count += print_char(va_arg(args, int));
			break;
		case 's':
			count += print_string(va_arg(args, const char *));
			break;
		case '%':
			my_putchar('%');
			count++;
			break;
		case 'd':
			count += print_dec(args);
			break;
		case 'i':
			count += print_int(args);
			break;
		default:
			{
				my_putchar('%');
				my_putchar(format);
				count += 2;
				break;
			}
	}
	return (count);
}

/**
 * process_format - entry point
 * @format: char
 * @args: va_list
 * Return: int
 */

int process_format(const char *format, va_list args)
{
	int count = 0;
	char c;

	while ((c = *format))
	{
		if (c == '%')
		{
			format++;
			count = process_format_specifier(*format, args, count);
		}
		else
		{
			my_putchar(c);
			count++;
		}
		format++;
	}
	return (count);
}
