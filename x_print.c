#include "holberton.h"
#include <stdlib.h>

/**
 * x_print - prints unsigned ints as lowercase hexadecimal numerals
 * when called by format tag in printf
 * @args: variable argument coming from _printf
 * Return: output length in bytes/chars
 */

int x_print(va_list args)
{
/*
 * takes u-ints, same logic as X, o, b. can they be combined with 'base' flag?
 * !!! remove pow test below if we clear all tests
 */
	unsigned int dec = va_arg(args, unsigned int);
	char *hex;
	unsigned int pow_16 = 1;
	int count = 1;
	int i;

	while (pow_16 <= (dec / 16))
	{
		pow_16 *= 16;
		count++;
	}

	hex = malloc(sizeof(char) * (count + 1));
	if (!hex)
	{
		free(hex);
		return (-1);
	}
	for (i = 0; i < count; i++)
	{
		if ((dec / pow_16) > 9)
			hex[i] = ((dec / pow_16) + 'W');
		else
			hex[i] = ((dec / pow_16) + '0');
		dec %= pow_16;
		pow_16 /= 16;
	}
/*not sure why exit value of i == count, shouldn't it be count - 1? */
	hex[i] = '\0';
	for (i = 0; hex[i]; i++)
		_putchar(hex[i]);

	free(hex);
	return (count);
}
/*  UINT_MAX = 4294967296 or 1111 1111 1111 1111 1111 1111 1111 1111 */
