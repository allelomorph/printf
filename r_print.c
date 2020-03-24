#include "holberton.h"
#include <stdlib.h>

/**
 * r_print - prints a string in reverse when called by format tag in printf
 * @args: variable argument list coming from _printf
 * Return: output length in bytes/chars
 */
int r_print(va_list args)
{
	int count = 0;
	int i;
	char *str = va_arg(args, char *);
	char *null_string = "(llun)";

	if (!str)
		str = null_string;

	for (i = 0; str[i]; i++)
	{
		count++;
	}

	i--;
	for (; i >= 0; i--)
	{
		_putchar(str[i]);
	}
	return (count);
}
