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
	unsigned int buffer_size, fi, bi;
	char *buffer;
	va_list ap;

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(ap, format);
	buffer_size = sizeof(char) * (_strlen(format) + 1);
	buffer = malloc(buffer_size);
	if (buffer == NULL)
		return (-1);
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
			case 's':
				buffer = string_handler(buffer, va_arg(ap, char *), &buffer_size, &bi);
				fi++;
				break;
			case '%':
				buffer[bi] = '%';
				fi++;
				break;
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