#include "holberton.h"
#include <stdlib.h>

/**
 * b_print - prints unsigned ints as binary code
 * when called by format tag in printf
 * @args: variable argument coming from _printf
 * Return: output length in bytes/chars
 */

int b_print(va_list args)
{
/*
 * takes u-ints, same logic as X, o, b. can they be combined with 'base' flag?
 * !!! remove pow test below if we clear all tests
 */
	unsigned int dec = va_arg(args, unsigned int);
	char *bin;
	unsigned int pow_2 = 1;
	int count = 1;
	int i;

	while (pow_2 <= (dec / 2))
	{
		pow_2 *= 2;
		count++;
	}

	bin = malloc(sizeof(char) * (count + 1));
	if (!bin)
	{
		free(bin);
		return (-1);
	}
	for (i = 0; i < count; i++)
	{
		bin[i] = ((dec / pow_2) + '0');
		dec %= pow_2;
		pow_2 /= 2;
	}
/*not sure why exit value of i == count, shouldn't it be count - 1? */
	bin[i] = '\0';
	for (i = 0; bin[i]; i++)
		putchar(bin[i]);
	putchar('\n');
	free(bin);
	return (count);
}
/* UINT_MAX = 4294967296 or 1111 1111 1111 1111 1111 1111 1111 1111 */
