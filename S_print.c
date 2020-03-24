#include "holberton.h"
#include <stdlib.h>

int SX_print(unsigned int dec);

int SX_print(unsigned int dec)
{
	char *HEX;
	unsigned int pow_16 = 1;
	int count = 1;
	int i;

	while (pow_16 <= (dec / 16))
	{
		pow_16 *= 16;
		count++;
	}
	HEX = malloc(sizeof(char) * (count + 1));
	if (!HEX)
	{
		free(HEX);
		return (-1);
	}
	for (i = 0; i < count; i++)
	{
		if (pow_16)
		{
			if ((dec / pow_16) > 9)
				HEX[i] = ((dec / pow_16) + '7');
			else
				HEX[i] = ((dec / pow_16) + '0');
			dec %= pow_16;
			pow_16 /= 16;
		}
		else
			HEX[i] = (0 + '0');
	}
	HEX[i] = '\0';
	for (i = 0; HEX[i]; i++)
		putchar(HEX[i]);
	free(HEX);
	return (count);
}

/**
 * S_print - prints string when called by format tag in printf,
 * formatting and printing non-standard ASCII values as hex numerals
 * @args: variable argument coming from _printf
 * Return: output length in bytes/chars
 */

int S_print(va_list args)
{
/*
 * takes char *
 * !!! remove pow test below if we clear all tests
 */
	int count = 0;
	int i;
	char *str = va_arg(args, char *);
	char *null_string = "(null)";

	if (!str)
		str = null_string;
	else
	{
		for (i = 0; str[i]; i++)
		{
			if ((str[i] > 0 && str[i] < 32) || str[i] >= 127)
			{
				_putchar('\\');
				_putchar('x');
				if (str[i] <= 15)
					_putchar('0');
/* how to call the function without valgrind error?? */
				count += SX_print((unsigned int)str[i]);
			}
			else
			{
				_putchar(str[i]);
				count++;
			}
		}
	}
	return (count);
}
