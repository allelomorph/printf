#include "holberton.h"
#include <stdlib.h>

/**
 * c_print - prints char when called by format tag in printf
 * @args: variable argument coming from _printf
 * Return: output length in bytes/chars
 */
int c_print(va_list args)
{
	int count = 0;

	_putchar(va_arg(args, int));
	count++;
	return (count);
}
