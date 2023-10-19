#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * char_handler - Handel char format specifier %c
 * @buffer: pointer to string that holds the buffer
 * @ap: variant argument list
 * @buffer_size: Old Buffer size
 * @index: Pointer to the index of the buffer
 *
 * Return: The new buffer
 */

char *char_handler(char *buffer, va_list ap,
		unsigned int *buffer_size, unsigned int *index)
{
	char character = (char) va_arg(ap, int);

	if (character == '\0')
	{
		return (buffer);
	}
	buffer = _realloc(buffer, *buffer_size, (*buffer_size + sizeof(char)));
	*buffer_size = *buffer_size + sizeof(char);
	buffer[*index] = character;
	return (buffer);
}

/**
 * string_handler - Handel string format specifier %s
 * @buffer: pointer to string that holds the buffer
 * @ap: variant argument list
 * @buffer_size: Old Buffer size
 * @index: Pointer to the index of the buffer
 *
 * Return: The new buffer
 */

char *string_handler(char *buffer, va_list ap, unsigned int *buffer_size,
					unsigned int *index)
{
	int j, len;
	char *string = va_arg(ap, char *);

	if (string == NULL)
		string = "(null)";
	len = _strlen(string);
	if (len == 0)
	{
		(*index)--;
		return (buffer);
	}
	buffer = _realloc(buffer, *buffer_size, (*buffer_size + len));
	*buffer_size = *buffer_size + len;
	for (j = 0; string[j]; j++)
	{
		buffer[*index] = string[j];
		if (string[j + 1] != '\0')
			(*index)++;
	}
	return (buffer);
}

/**
 * num_handler - Handel format specifier %d & %i
 * @buffer: pointer to string that holds the buffer
 * @ap: variant argument list
 * @buffer_size: Old Buffer size
 * @index: Pointer to the index of the buffer
 *
 * Return: The new buffer
 */

char *num_handler(char *buffer, va_list ap, unsigned int *buffer_size,
					unsigned int *index)
{
	long num = va_arg(ap, int);
	long tmp = num, num_dig = 0, minus = 0;

	if (num == 0)
	{
		buffer[(*index)++] = '0';
	}
	if (num < 0)
	{
		buffer[(*index)++] = '-';
		minus++;
		num *= -1;
		tmp *= -1;
	}
	while (tmp > 0)
	{
		tmp /= 10;
		num_dig++;
	}
	buffer = _realloc(buffer, *buffer_size, (*buffer_size + num_dig + minus));
	*buffer_size = *buffer_size + num_dig + minus;
	while (num_dig > 0)
	{
		buffer[(*index)++] = (num / square10(num_dig) + '0');
		num %= square10(num_dig);
		num_dig -= 1;
	}
	(*index)--;
	return (buffer);
}

/**
 * binary_handler - convert digit from base 10 to 2
 * @buffer: pointer to string that holds the buffer
 * @ap: variant argument list
 * @buffer_size: Old Buffer size
 * @index: Pointer to the index of the buffer
 *
 * Return: The new buffer
 */

char *binary_handler(char *buffer, va_list ap, unsigned int *buffer_size,
					unsigned int *index)
{
	int remainder, i = 0, tmp_len;
	char tmp[1024];
	unsigned int num = va_arg(ap, unsigned int);

	if (num == 0)
	{
		buffer[*index] = '0';
		return (buffer);
	}
	while (num > 0)
	{
		remainder = num % 2;
		num /= 2;
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

/**
 * u_num_handler - Handel format specifier %u
 * @buffer: pointer to string that holds the buffer
 * @ap: variant argument list
 * @buffer_size: Old Buffer size
 * @index: Pointer to the index of the buffer
 *
 * Return: The new buffer
 */

char *u_num_handler(char *buffer, va_list ap, unsigned int *buffer_size,
					unsigned int *index)
{
	unsigned int num = va_arg(ap, unsigned int);
	unsigned int tmp = num;
	int num_dig = 0;

	if (num == 0)
	{
		buffer[*index] = '0';
		return (buffer);
	}
	while (tmp > 0)
	{
		tmp /= 10;
		num_dig++;
	}
	buffer = _realloc(buffer, *buffer_size, (*buffer_size + num_dig));
	*buffer_size = *buffer_size + num_dig;
	while (num_dig > 0)
	{
		buffer[(*index)++] = (num / square10(num_dig) + '0');
		num %= square10(num_dig);
		num_dig -= 1;
	}
	(*index)--;
	return (buffer);
}
