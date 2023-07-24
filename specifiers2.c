#include "main.h"

/**
 * print_unsigned - prints integer
 * @args: argument to print
 * Return: number of characters printed
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
/**
 * print_bin - prints a binary number.
 * @val: arguments.
 * Return: 1.
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
