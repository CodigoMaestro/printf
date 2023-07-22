#include <stdarg.h>
#include "main.h"

/**
 * print_char - entry point
 * @c: char
 * Return: int
 */

int print_char(char c)
{
	my_putchar(c);
	return (1);
}

/**
 * print_string - entry point
 * @str: char
 * Return: 0
 */

int print_string(const char *str)
{
	int count = 0;

	if (str == NULL)
		return (0);

	while (*str)
	{
		my_putchar(*str);
		str++;
		count++;
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

			if (*format == '%')
			{
				return (-1);
			}
			else if (*format == '% ')
			{
				return (-1)
			}
			else
			{
				switch (*format)
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
					default:
						{
							my_putchar('%');
							my_putchar(*format);
							count += 2;
							break;
						}
				}
			}
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

/**
 * _printf - entry point
 * @format: char
 * Return: 0
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count;

	va_start(args, format);
	count = process_format(format, args);

	va_end(args);
	return (count);
}

