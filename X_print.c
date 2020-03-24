#include "holberton.h"
#include <stdlib.h>

/**
 * X_print - prints unsigned ints as uppercase hexadecimal numerals
 * when called by format tag in printf
 * @args: variable argument coming from _printf
 * Return: output length in bytes/chars
 */

int X_print(va_list args)
{
/*
 * takes u-ints, same logic as x, o, b. can they be combined with 'base' flag?
 * !!! remove pow test below if we clear all tests
 */
	unsigned int dec = va_arg(args, unsigned int);
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
		if ((dec / pow_16) > 9)
			HEX[i] = ((dec / pow_16) + '7');
		else
			HEX[i] = ((dec / pow_16) + '0');

		dec %= pow_16;
		pow_16 /= 16;
	}
/*not sure why exit value of i == count, shouldn't it be count - 1? */
	HEX[i] = '\0';

	for (i = 0; HEX[i]; i++)
		_putchar(HEX[i]);

	free(HEX);
	return (count);
}
/*  UINT_MAX = 4294967296 or 1111 1111 1111 1111 1111 1111 1111 1111 */
