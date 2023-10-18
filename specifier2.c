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
        address = "(nil)";
        print_buffer(buffer);
        print_buffer(address);
        *index = 0;
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