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
