#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * char_handler - Handel char format specifier %c
 * @buffer: pointer to string that holds the buffer
 * @character: the char to be added to the buffer
 * @buffer_size: Old Buffer size
 * @index: Pointer to the index of the buffer
 *
 * Return: The new buffer
 */

char *char_handler(char *buffer, char character,
		unsigned int *buffer_size, unsigned int *index)
{
	buffer = _realloc(buffer, *buffer_size, (*buffer_size + sizeof(char)));
	*buffer_size = *buffer_size + sizeof(char);
	buffer[*index] = character;
	return (buffer);
}

/**
 * string_handler - Handel string format specifier %s
 * @buffer: pointer to string that holds the buffer
 * @string: the string to be added to the buffer
 * @buffer_size: Old Buffer size
 * @index: Pointer to the index of the buffer
 *
 * Return: The new buffer
 */

char *string_handler(char *buffer, char *string, unsigned int *buffer_size,
					unsigned int *index)
{
	int j;

	buffer = _realloc(buffer, *buffer_size, (*buffer_size + _strlen(string)));
	*buffer_size = *buffer_size + _strlen(string);
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
 * @num: Number to print
 * @buffer_size: Old Buffer size
 * @index: Pointer to the index of the buffer
 * 
 * Return: The new buffer
 */

char *num_handler(char *buffer, int num, unsigned int *buffer_size,
					unsigned int *index)
{
	int tmp = num, num_dig = 0, minus = 0;

	if (num > INT_MAX || num < INT_MIN)
		return (buffer);
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
 * @num: Unsigned number to print
 * @buffer_size: Old Buffer size
 * @index: Pointer to the index of the buffer
 * 
 * Return: The new buffer
 */

char *binary_handler(char *buffer, unsigned int num, unsigned int *buffer_size,
					unsigned int *index)
{
	int remainder, i = 0, tmp_len;
	char tmp[1024];

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