#include "main.h"

/**
 * format_handler - Handle the format to shorten the _printf
 * @ap: va_list
 * @list: struct f_list
 * @format: the format to be printed
 *
 * Return: Buffer size
 */

int format_handler(va_list ap, f_list list[], const char *format)
{
	int i, unknown = 0;
	unsigned int buffer_size, fi, bi;
	char *buffer;

	buffer_size = sizeof(char) * (_strlen(format) + 1);
	buffer = malloc(buffer_size);
	if (buffer == NULL)
		return (-1);
	for (fi = 0, bi = 0; format[fi] != '\0'; fi++, bi++)
	{
		if (format[fi] == '%')
		{
			for (i = 0; list[i].c != '\0'; i++)
			{
				if (list[i].c == format[fi + 1])
				{
					buffer = list[i].spec(buffer, ap, &buffer_size, &bi);
					fi++;
					unknown++;
					break;
				}
			}
			if (unknown == 0)
				buffer[bi] = format[fi];
		}
		else
			buffer[bi] = format[fi];
	}
	buffer[bi] = '\0';
	buffer_size = _strlen(buffer);
	if (buffer_size == 0)
	{
		buffer[bi] = '\n';
		buffer_size++;
	}
	write(1, buffer, buffer_size);
	free(buffer);
	return (buffer_size);
}
