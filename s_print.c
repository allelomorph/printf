#include "holberton.h"
#include <stdlib.h>

/**
 * s_print - prints string when called by format tag in printf
 * @args: variable argument coming from _printf
 * Return: output length in bytes/chars
 */
int s_print(va_list args)
{
	int count = 0;
	int i;
	char *str = va_arg(args, char *);
	char *null_string = "(null)";

	if (!str)
		str = null_string;

	for (i = 0; str[i]; i++)
	{
		_putchar(str[i]);
		count++;
	}

	return (count);
}
