#include "main.h"
#include <stdlib.h>

/**
 * custom_string - Prints a custom string with non-printable characters as hex.
 * @args: va_list containing the string to print.
 * Return: The number of characters printed.
 */

int custom_string(va_list args)
{
	char *s;
	int i, len = 0;
	int cast;

	s = va_arg(args, char *);
	if (s == NULL)
		s = "(null)";
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] < 32 || s[i] >= 127)
		{
			my_putchar('\\');
			my_putchar('x');
			len = len + 2;
			cast = s[i];
			if (cast < 16)
			{
				my_putchar('0');
				len++;
			}
			len = len + print_hex_helper(cast);
		}
		else
		{
			my_putchar(s[i]);
			len++;
		}
	}
	return (len);
}

/**
 * print_hex_helper - Prints the hexadecimal representation of a number.
 * @num: The number to convert to hexadecimal.
 * Return: The number of characters printed.
 */

int print_hex_helper(unsigned int num)
{
	int i;
	int *array;
	int counter = 0;
	unsigned int temp = num;

	while (num / 16 != 0)
	{
		num /= 16;
		counter++;
	}
	counter++;
	array = malloc(counter * sizeof(int));

	for (i = 0; i < counter; i++)
	{
		array[i] = temp % 16;
		temp /= 16;
	}
	for (i = counter - 1; i >= 0; i--)
	{
		if (array[i] > 9)
			array[i] = array[i] + 7;
		my_putchar(array[i] + '0');
	}
	free(array);
	return (counter);
}

/**
 * print_pointer - Prints the hexadecimal representation of a pointer address.
 * @args: va_list containing the pointer to print.
 * Return: The number of characters printed.
 */

int print_pointer(va_list args)
{
	void *p;
	char *s = "(nil)";
	long int a;
	int b;
	int i;

	p = va_arg(args, void*);
	if (p == NULL)
	{
		for (i = 0; s[i] != '\0'; i++)
		{
			my_putchar(s[i]);
		}
		return (i);
	}

	a = (unsigned long int)p;
	my_putchar('0');
	my_putchar('x');
	b = print_hex_helper(a);
	return (b + 2);
}
