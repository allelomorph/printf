#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

/**
  * struct datatype - datatype struct
  * @f_ptr: function pointer
  * @tag: data type to match
  */

typedef struct datatype
{
	char *tag;
	int (*f_ptr)(va_list args);
} data_t;

int _putchar(char c);
int _printf(const char *format, ...);
int b_print(va_list args);
int c_print(va_list args);
int di_print(va_list args);
int o_print(va_list args);
int p_print(va_list args);
int perc_print(va_list args);
int r_print(va_list args);
int R_print(va_list args);
int s_print(va_list args);
int S_print(va_list args);
int u_print(va_list args);
int x_print(va_list args);
int X_print(va_list args);

#endif
