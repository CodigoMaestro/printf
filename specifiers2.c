#include "main.h"
#include <stdlib.h>

/**
 * print_u - Prints an unsigned integer in decimal format
 * @args: va_list containing the unsigned integer to print
 * Return: Number of characters printed
 */

int print_u(va_list args)
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

/**
 * print_bin - Prints an unsigned integer in binary format
 * @val: va_list containing the unsigned integer to print
 * Return: Number of characters printed
 */

int print_bin(va_list val)
{
	int flag = 0;
	int cont = 0;
	int i, a = 1, b;
	unsigned int num = va_arg(val, unsigned int);
	unsigned int p;

	for (i = 0; i < 32; i++)
	{
		p = ((a << (31 - i)) & num);
		if (p >> (31 - i))
			flag = 1;
		if (flag)
		{
			b = p >> (31 - i);
			my_putchar(b + 48);
			cont++;
		}
	}
	if (cont == 0)
	{
		cont++;
		my_putchar('0');
	}
	return (cont);
}

/**
 * print_octal - Prints an unsigned integer in octal format.
 * @args: va_list containing the unsigned integer to print.
 * Return: Number of characters printed.
 */

int print_octal(va_list args)
{
	int i;
	int *array;
	int counter = 0;
	unsigned int num = va_arg(args, unsigned int);
	unsigned int temp = num;

	while (num / 8 != 0)
	{
		num /= 8;
		counter++;
	}
	counter++;
	array = malloc(counter * sizeof(int));

	for (i = 0; i < counter; i++)
	{
		array[i] = temp % 8;
		temp /= 8;
	}
	for (i = counter - 1; i >= 0; i--)
	{
		my_putchar(array[i] + '0');
	}
	free(array);
	return (counter);
}

/**
 * print_hexa - Prints an unsigned integer in hexadecimal 
 * format (lowercase).
 * @args: va_list containing the unsigned integer to print
 * Return: Number of characters printed
 */

int print_hexa(va_list args)
{
	int i;
	int *array;
	int counter = 0;
	unsigned int num = va_arg(args, unsigned int);
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
 * print_hex - Prints an unsigned integer in hexadecimal 
 * format (uppercase).
 * @args: va_list containing the unsigned integer to print.
 * Return: Number of characters printed.
 */

int print_hex(va_list args)
{
	int i;
	int *array;
	int counter = 0;
	unsigned int num = va_arg(args, unsigned int);
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
			array[i] = array[i] + 39;
		my_putchar(array[i] + '0');
	}
	free(array);
	return (counter);
}
