#include "holberton.h"
#include <stdlib.h>
/*
 * recycles code from x_print, but with unsigned long ints to accomodate large
 * integer values of memory addresses. can the redundant logic across helpers
 * be consolidated? as per man 3 printf %p is equivalent to %#x or %#lx, on
 * my machine, it's %#lx. takes void * as arg.
 */

/**
 * p_print - prints pointer addresses stored as unsigned long ints as lowercase
 * hexadecimals with a leading '0x' when called by format tag in printf
 * @args: variable argument coming from _printf
 * Return: output length in bytes/chars
 */

int p_print(va_list args)
{
	char *hex;
	unsigned long int pow_16 = 1;
	int count = 1;
	int i;
	void *temp = va_arg(args, void *);
	unsigned long int dec = (unsigned long int)temp;

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
	i++;
	hex[i] = '\0';
	putchar('0');
	putchar('x');
	count += 2;
	for (i = 0; hex[i]; i++)
		putchar(hex[i]);

	free(hex);
	return (count);
}
