#include "main.h"

/**
 * octal_handler - convert digit from base 10 to 8
 * @buffer: pointer to string that holds the buffer
 * @ap: variant argument list
 * @buffer_size: Old Buffer size
 * @index: Pointer to the index of the buffer
 *
 * Return: The new buffer
 */

char *octal_handler(char *buffer, va_list ap, unsigned int *buffer_size,
					unsigned int *index)
{
	unsigned int num = va_arg(ap, unsigned int);
	int remainder, i = 0, tmp_len;
	char tmp[1024];

	while (num > 0)
	{
		remainder = num % 8;
		num /= 8;
		tmp[i++] = remainder + '0';
	}
	tmp[i] = '\0';
	tmp_len = _strlen(tmp);
	buffer = _realloc(buffer, *buffer_size, *buffer_size + tmp_len);
	*buffer_size += tmp_len;
	while (i >= 0)
	{
		buffer[(*index)++] = tmp[i - 1];
		i--;
	}
	*index -= 2;
	return (buffer);
}
