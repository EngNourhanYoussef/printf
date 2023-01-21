#include "main.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
/**
  * _printf - create printf function
  * @format: passed mutlible format
  * Return: no. of character printed
  */
int _printf(const char *format, ...)
{
	int i, blen, hln;
	double totalBuffer;
	double *totale;
	va_list argp;
	char buffer[BUFSIZE], *holder;
	char *(*pointer_get_valod)(va_list);

	for (i = 0; i < BUFSIZE; i++)
	{
		buffer[i] = 0;
	}
	totalBuffer = 0;
	pointer_get_valid = NULL;
	total = &totalBuffer;
	va_start(argp, format);
	for (i = blen = hlen = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			pointer_get_valid = get_valid_type(format[i + 1]);
			holder = (pointer_get_valid == NULL) ?
				found_nothing(format[i + 1]) :
				pointer_get_valid(argp);
			hlen = _strlen(holder);
			blen = blen = alloc_buffer(holder, hlen, buffer, blen, total);
			i++;
		}
		else
		{
			holder = ctos(format[i]);
			blen = alloc_buffer(holder, 1, buffer, blen, total);
		}
	}
	va_end(argp);
	_puts(buffer, blen);
	return (totalBuffer + blen);
}
