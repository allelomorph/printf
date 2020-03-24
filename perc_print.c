#include "holberton.h"
#include <stdlib.h>

/**
 * perc_print - prints percent sign when called by format tag in printf
 * @args: variable argument coming from _printf
 * Return: output length in bytes/chars
 */
int perc_print(va_list args)
{
	int count = 0;
	(void)args;

	_putchar('%');
	count++;
	return (count);
}
