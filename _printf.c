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
	{'r', rev_string}, {'R', rot13_handler}, {'p', address_handler},
	{'S', non_printable}, {'\0', NULL}
};

	unsigned int buffer_size;
	va_list ap;

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(ap, format);
	buffer_size = format_handler(ap, list, format);
	va_end(ap);
	return (buffer_size);
}
