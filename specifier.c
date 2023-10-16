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

	if (sizeof(string) != sizeof(char *))
		exit(-1);
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
