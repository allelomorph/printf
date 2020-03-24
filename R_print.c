#include "holberton.h"
#include <stdlib.h>
/*
 * every attempt to directly modify str[i] resutled in seg faults.
 *  so, string duplicating into temp.
 */

/**
 * R_print - prints a string in Rot13 when called by format tag in printf
 * @args: variable argument list coming from _printf
 * Return: output length in bytes/chars
 */
int R_print(va_list args)
{
	int count = 0;
	int i, j;
	char *str = va_arg(args, char *);
	char *rem = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *rep = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *temp;
	char *null_string = "(null)";

	for (; str[count]; count++)
	{}
	temp = malloc(sizeof(char) * (count + 1));
	if (!temp)
	{
		free(temp);
		return (-1);
	}
	if (!str)
		str = null_string;
	for (i = 0; str[i]; i++)
	{
		temp[i] = str[i];
	}
	temp[i] = '\0';
	for (i = 0; temp[i]; i++)
	{
		for (j = 0; rem[j]; j++)
		{
			if (temp[i] == rem[j])
			{
				temp[i] = rep[j];
				break;
			}

		}
	}
	for (i = 0; temp[i]; i++)
		_putchar(temp[i]);

	free(temp);
	return (count);
}
