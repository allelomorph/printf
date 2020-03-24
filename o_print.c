#include "holberton.h"
#include <stdlib.h>

/**
 * o_print - prints unsigned ints as octal numerals when called
 * by format tag in printf
 * @args: variable argument coming from _printf
 * Return: output length in bytes/chars
 */

int o_print(va_list args)
{
/*
 * takes u-ints, same logic as x, X, b. can they be combined with 'base' flag?
 * !!! remove pow test below if we clear all tests
 */
	unsigned int dec = va_arg(args, unsigned int);
	char *oct;
	unsigned int pow_8 = 1;
	int count = 1;
	int i;

	while (pow_8 <= (dec / 8))
	{
		pow_8 *= 8;
		count++;
	}

	oct = malloc(sizeof(char) * (count + 1));

	if (!oct)
	{
		free(oct);
		return (-1);
	}
	for (i = 0; i < count; i++)
	{
		oct[i] = ((dec / pow_8) + '0');
		dec %= pow_8;
		pow_8 /= 8;
	}
/*not sure why exit value of i == count, shouldn't it be count - 1? */
	oct[i] = '\0';
	for (i = 0; oct[i]; i++)
		_putchar(oct[i]);
	free(oct);
	return (count);
}
