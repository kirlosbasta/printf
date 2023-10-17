#include "main.h"
/**
 * _printf - printf like function
 * @format: string may contain format specifier
 *
 * Return: The length of string
 */
int _printf(const char *format, ...)
{
	f_list list[] = {
	{'c', char_handler}, {'s', string_handler}, {'d', num_handler},
	{'i', num_handler}, {'b', binary_handler}, {'u', u_num_handler},
	{'o', octal_handler}, {'x', hexadecimal_handler}, {'X', Hexadecimal_handler}, 
	{'\0', NULL}
};
	int i, unknown = 0;
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
			if (format[fi + 1] == '%')
			{
				buffer[bi] = '%';
				fi++;
			}
			if (unknown == 0)
				buffer[bi] = format[fi];
		}
		else
			buffer[bi] = format[fi];
	}
	buffer[bi] = '\0';
	buffer_size = _strlen(buffer);
	write(1, buffer, buffer_size);
	free(buffer);
	va_end(ap);
	return (buffer_size);
}
