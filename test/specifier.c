#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * char_handler - Handel format specifier %c
 * @buffer: pointer to string that holds the buffer
 * @character: the char to be added to the buffer
 * @buffer_size: Old Buffer size
 * @index: Pointer to the index of the buffer
 * 
 * Return: The new buffer
 */

char *char_handler(char *buffer, char character, unsigned int * buffer_size, unsigned int *index)
{
    buffer = _realloc(buffer, *buffer_size, (*buffer_size + sizeof(char)));
    buffer[*index] = character;
    return (buffer);
}