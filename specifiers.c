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
 * print_binary - entry point
 * @num: va_list
 * Return: int
 */

int print_binary(unsigned int num)
{
	int count = 0;
	int i;
	int bits = sizeof(unsigned int) * 8;
	int bit;

	for (i = bits - 1; i >= 0; i--)
	{
		bit = (num >> i) & 1;
		my_putchar(bit + '0');
		count++;
	}
	return (count);
}

