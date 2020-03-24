#include "holberton.h"
#include <stdlib.h>

/**
 * u_print - prints unsigned ints in base 10 when called by
 * format tag in printf
 * @args: variable argument coming from _printf
 * Return: output length in bytes/chars
 */

int u_print(va_list args)
{
/*
 * takes u-ints, same logic as o, x, X, b. can be combined with 'base' flag?
 * !!! remove pow test below if we clear all tests
 */
	unsigned int dec = va_arg(args, unsigned int);
	char *uns;
	unsigned int pow_10 = 1;
	int count = 1;
	int i;

	while (pow_10 <= (dec / 10))
	{
		pow_10 *= 10;
		count++;
	}
	uns = malloc(sizeof(char) * (count + 1));

	if (!uns)
	{
		free(uns);
		return (-1);
	}
	for (i = 0; i < count; i++)
	{
		uns[i] = ((dec / pow_10) + '0');
		dec %= pow_10;
		pow_10 /= 10;
	}
/*not sure why exit value of i == count, shouldn't it be count - 1? */
	uns[i] = '\0';

	for (i = 0; uns[i]; i++)
		putchar(uns[i]);

	free(uns);
	return (count);
}
/*  UINT_MAX = 4294967296 or 1111 1111 1111 1111 1111 1111 1111 1111 */
