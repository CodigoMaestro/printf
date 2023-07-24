#include "main.h"

/**
 * custom_string - entry point
 * @args: va_list
 * Return: int
 */

int custom_string(va_list args)
{
	char *s;
	int i, len = 0;
	int cast;

	s = va_arg(val, char *);
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
 * print_hex_helper - entry point
 * @num: int
 * Return: int
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
