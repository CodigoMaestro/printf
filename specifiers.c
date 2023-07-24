#include "main.h"
#include <string.h>
#include <stdio.h>

/**
 * _strlen - entry point
 * @str: char
 * Return: length
 */

size_t _strlen(const char *str)
{
	size_t length = 0;

	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

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
	/*int count = 0;*/
	int i, len;

	if (str == NULL)
	{
		str = "(null)";
		len = _strlen(str);
		for (i = 0; i < len; i++)
			my_putchar(str[i]);
		return (len);
	}
	else
	{
		len = _strlen(str);
		for (i = 0; i < len; i++)
			my_putchar(str[i]);
		return (len);
	}
}

/**
 * print_unsigned - entry point
 * @args: va_list
 * Return: int
 */

int print_unsigned(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
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
