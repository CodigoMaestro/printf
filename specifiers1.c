#include "main.h"
#include <string.h>
#include <stdio.h>

int print_char(char c);
int print_string(const char *str);
int print_integer(int num);

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
		case 'i':
			{
				int num = va_arg(args, int);

				count += print_integer(num);
				break;
			}
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
