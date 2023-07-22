#include "main.h"
#include <stdarg.h>

/**
 * print_char - entry point
 * @container: va_list
 * Return: void
 */

void print_char(va_list container)
{
	char c = va_arg(container, int);

	my_putchar(c);
}

/**
 * print_str - entry point
 * @container: va_list
 * Return: int
 */

int print_str(va_list container)
{
	char *s;
	int char_count = 0;

	s = va_arg(container, char *);
	while (*s)
	{
		my_putchar(*s);
		s++;
		char_count++;
	}
	return (char_count);
}

void print_decimal(va_list container)
{
	unsigned int d;

	d = va_arg(container, int);

	if (d < 0)
	{
		d = -d;
	}
	my_putchar('-');
	my_putchar(d);
}
/**
 * _printf - entry point
 * @format: char
 * Return: int
 */

int _printf(const char *format, ...)
{
	int char_count = 0;
	va_list container;

	va_start(container, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			switch (*format)
			{
				case 'c':
					print_char(container);
					char_count++;
					break;
				case 's':
					print_str(container);
					break;
				case '%':
					my_putchar('%');
					char_count++;
					break;
				case 'd':
					print_decimal(container);
				default:
					my_putchar('%');
					my_putchar(*format);
					char_count += 2;
					break;
			}
		}
		else
		{
			my_putchar(*format);
			char_count++;
		}
		format++;
	}
	va_end(container);
	return (char_count);
}
