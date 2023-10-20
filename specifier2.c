#include "main.h"

/**
 * address_handler - Print the address
 * @buffer: pointer to string that holds the buffer
 * @ap: variant argument list
 * @buffer_size: Old Buffer size
 * @index: Pointer to the index of the buffer
 *
 * Return: The new buffer
 */

char *address_handler(char *buffer, va_list ap, unsigned int *buffer_size,
			unsigned int *index)
{
	void *address = va_arg(ap, void *);
	unsigned int remainder, tmp_len;
	int i = 0;
	char hex[] = "0123456789abcdef";
	char tmp[1024];
	unsigned long address_num = (unsigned long) address;

	if (address == NULL)
	{
		buffer = _realloc(buffer, *buffer_size, (*buffer_size + 5));
		*buffer_size += 5;
		buffer[(*index)++] = '(';
		buffer[(*index)++] = 'n';
		buffer[(*index)++] = 'i';
		buffer[(*index)++] = 'l';
		buffer[(*index)] = ')';
		return (buffer);
	}
	while (address_num > 0)
	{
		remainder = address_num % 16;
		address_num /= 16;
		tmp[i++] = hex[remainder];
	}
	tmp[i] = '\0';
	tmp_len = _strlen(tmp);
	buffer = _realloc(buffer, *buffer_size, (*buffer_size + tmp_len));
	*buffer_size += tmp_len;
	buffer[(*index)++] = '0';
	buffer[(*index)++] = 'x';
	while (i >= 0)
	{
		buffer[(*index)++] = tmp[i - 1];
		i--;
	}
	*index -= 2;
	return (buffer);
}

/**
 * non_printable - convert non printable character to \x followed by hex ascii
 * @buffer: pointer to string that holds the buffer
 * @ap: variant argument list
 * @buffer_size: Old Buffer size
 * @index: Pointer to the index of the buffer
 *
 * Return: The new buffer
 */

char *non_printable(char *buffer, va_list ap, unsigned int *buffer_size,
			unsigned int *index)
{
	int i, j, x;
	char *string = va_arg(ap, char *);
	char *tmp = malloc(3);

	if (string == NULL)
	{
		print_buffer("(nil)");
		return (buffer);
	}
	for (i = 0, j = 0; string[i] != '\0'; i++)
	{
		if ((string[i] > 0 && string[i] < 32) || string[i] >= 127)
			j++;
	}
	buffer = _realloc(buffer, *buffer_size,
			*buffer_size + (j * 4) + _strlen(string));
	*buffer_size += (j * 4) + _strlen(string);
	for (i = 0; string[i] != '\0'; i++)
	{
		if ((string[i] > 0 && string[i] < 32) || string[i] >= 127)
		{
			buffer[(*index)++] = 92;
			buffer[(*index)++] = 'x';
			tmp = c_hex((int)string[i], tmp);
			x = 0;
			while (tmp[x] != '\0')
			{
				buffer[(*index)++] = tmp[x++];
			}
		}
		else
		{
			buffer[(*index)++] = string[i];
		}
	}
	(*index)--;
	free(tmp);
	return (buffer);
}

/**
 * percent_handler - Handle double percent
 * @buffer: pointer to string that holds the buffer
 * @ap: variant argument list
 * @buffer_size: Old Buffer size
 * @index: Pointer to the index of the buffer
 *
 * Return: The new buffer
 */

char *percent_handler(char *buffer, UNUSED va_list ap,
	UNUSED unsigned int *buffer_size, unsigned int *index)
{
	buffer[*index] = '%';
	return (buffer);
}
