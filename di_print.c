#include "holberton.h"
#include <stdlib.h>

/*
 * refactor adapted from u_print, but casting int to unsigned absolute value to
 * manage over/underflow
 */

/**
 * di_print - prints signed int as string when called by format tag in printf
 * @args: variable argument coming from _printf
 * Return: output length in bytes/chars
 */
int di_print(va_list args)
{
	int dec = va_arg(args, int);
	char *itgr;
	unsigned int pow_10 = 1, temp;
	int i, count = 1, neg = 0;

	if (dec < 0)
	{
		putchar('-');
		neg = 1;
		temp = (unsigned int)-dec;
	}
	else
		temp = (unsigned int)dec;
	while (pow_10 <= (temp / 10))
	{
		pow_10 *= 10;
		count++;
	}
	itgr = malloc(sizeof(char) * (count + 1));
	if (!itgr)
	{
		free(itgr);
		return (-1);
	}
	for (i = 0; i < count; i++)
	{
		itgr[i] = (temp / pow_10 + '0');
		temp %= pow_10;
		pow_10 /= 10;
	}
	if (neg != 0)
		count++;
	i++;
	itgr[i] = '\0';
	for (i = 0; itgr[i]; i++)
		putchar(itgr[i]);

	free(itgr);
	return (count);
}
