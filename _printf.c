#include "holberton.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printf - produces output according to format
 * @format: datatype to print
 * Return: input length
 */
int _printf(const char * const format, ...)
{
	int i = 0, j, count = 0;
	va_list args;

	data_t type[] = {
		{"b", b_print}, {"c", c_print}, {"d", di_print},
		{"i", di_print}, {"o", o_print}, {"p", p_print},
		{"%", perc_print}, {"r", r_print}, {"R", R_print},
		{"s", s_print}, {"S", S_print}, {"u", u_print},
		{"x", x_print}, {"X", X_print},
	};
	va_start(args, format);

	if ((format == NULL) || (format[i] == '%' && format[i + 1] == '\0'))
		return (-1);
	if (format[i] == '%' && format[i + 1] == ' ')
		return (-1);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			count += _putchar(format[i]);
			continue;
		}
		for (j = 0; type[j].tag; j++)
		{
			if (*type[j].tag == format[i + 1])
			{
				count += type[j].f_ptr(args);
				break;
			}
		}
		i++;
		if (!type[j].tag)
		{
			count += _putchar('%');
			count += _putchar(format[i]);
		}
	}
	va_end(args);
	return (count);
}
