#include "main.h"
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * _printf - printf like function
 * @format: string may contain format specifier
 *
 * Return: The length of string
 */

int _printf(const char *format, ...)
{
	int fi, bi;
	unsigned int buffer_size;
	char *buffer;
	va_list ap;

	va_start(ap, format);
	if (format == NULL)
	{
		return (0);
	}
	buffer_size = sizeof(char) * (_strlen(format) + 1);
	buffer = malloc(buffer_size);
	if (buffer == NULL)
	{
		return (0);
	}
	for (fi = 0, bi = 0; format[fi] != '\0'; fi++, bi++)
	{
		if (format[fi] == '%')
		{
			switch (format[fi + 1])
			{
			case 'c':
				buffer = char_handler(buffer, (char) va_arg(ap, int), &buffer_size, &bi);
				fi++;
				break;
			case 'C':
				buffer = char_handler(buffer, (char) va_arg(ap, int), &buffer_size, &bi);
				fi++;
				break;
			case '%':
				buffer[bi] = '%';
				fi++;
			default:
				buffer[bi] = format[fi];
			}
		}
		else
		{
			buffer[bi] = format[fi];
		}
	}
	buffer[bi] = '\0';
	buffer_size = _strlen(buffer);
	write(1, buffer, buffer_size);
	free(buffer);
	va_end(ap);
	return (buffer_size);
}


