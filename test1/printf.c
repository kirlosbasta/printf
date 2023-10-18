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

char buffer[BUFFER_SIZE];
int index = 0, i, j;
unsigned int len = 0;
va_list ap;

va_start(ap, format);
if (format == NULL || (format[0] == '%' && format[1] == '\0'))
	return (-1);
for (i = 0; format[i] != '\0'; i++)
{
    if (index + 1 == BUFFER_SIZE)
    {
        buffer[index] =  '\0';
        print_buffer(buffer);
        index = 0;
    }
    if (format[i] == '%')
    {
        for (j = 0; list[j].c != '\0'; j++)
			{
				if (list[j].c == format[i + 1])
				{
                    print_buffer(buffer);
                    index = 0;
					len = list[j].spec(ap);
					break;
				}
			}
    }
    else
    {
        buffer[index++] = format[i];
        len++;

    }
}
va_end(ap);
buffer[index++] = '\0';
print_buffer(buffer);
return (len + 1);
}