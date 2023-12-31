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

	if (num == 0)
	{
		buffer[*index] = '0';
		return (buffer);
	}
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

/**
 * hexadecimal_handler - convert digit from base 10 to 16
 * @buffer: pointer to string that holds the buffer
 * @ap: variant argument list
 * @buffer_size: Old Buffer size
 * @index: Pointer to the index of the buffer
 *
 * Return: The new buffer
 */
char *hexadecimal_handler(char *buffer, va_list ap, unsigned int *buffer_size,
					unsigned int *index)
{
	unsigned int num = va_arg(ap, long int);
	long int remainder, tmp_len;
	int i = 0;
	char hex[] = "0123456789abcdef";
	char tmp[1024];

	if (num == 0)
	{
		buffer[*index] = '0';
		return (buffer);
	}
	while (num > 0)
	{
		remainder = num % 16;
		num /= 16;
		tmp[i++] = hex[remainder];
	}
	tmp[i] = '\0';
	tmp_len = _strlen(tmp);
	buffer = _realloc(buffer, *buffer_size, (*buffer_size + tmp_len));
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
 * hexadecimal_handler - convert digit from base 10 to 16
 * @buffer: pointer to string that holds the buffer
 * @ap: variant argument list
 * @buffer_size: Old Buffer size
 * @index: Pointer to the index of the buffer
 *
 * Return: The new buffer
 */
char *Hexadecimal_handler(char *buffer, va_list ap, unsigned int *buffer_size,
					unsigned int *index)
{
	unsigned int num = va_arg(ap, unsigned long int);
	unsigned int remainder, tmp_len;
	int i = 0;
	char hex[] = "0123456789ABCDEF";
	char tmp[1024];

	if (num == 0)
	{
		buffer[*index] = '0';
		return (buffer);
	}
	while (num > 0)
	{
		remainder = num % 16;
		num /= 16;
		tmp[i++] = hex[remainder];
	}
	tmp[i] = '\0';
	tmp_len = _strlen(tmp);
	buffer = _realloc(buffer, *buffer_size, (*buffer_size + tmp_len));
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
 * rev_string - reverse the string of %r
 * @buffer: pointer to string that holds the buffer
 * @ap: variant argument list
 * @buffer_size: Old Buffer size
 * @index: Pointer to the index of the buffer
 *
 * Return: The new buffer
 */

char *rev_string(char *buffer, va_list ap, unsigned int *buffer_size,
				 unsigned int *index)
{
	char *string = va_arg(ap, char *);
	int tmp_len;

	if (string == NULL)
		return (buffer);
	tmp_len = _strlen(string);
	buffer = _realloc(buffer, *buffer_size, *buffer_size + tmp_len);
	*buffer_size += tmp_len;
	while (tmp_len > 0)
	{
		buffer[(*index)++] = string[tmp_len - 1];
		tmp_len--;
	}
	(*index)--;
	return (buffer);
}

/**
 * rot13_handler - Handel custoum format specifier %R
 * @buffer: pointer to string that holds the buffer
 * @ap: variant argument list
 * @buffer_size: Old Buffer size
 * @index: Pointer to the index of the buffer
 *
 * Return: The new buffer
 */

char *rot13_handler(char *buffer, va_list ap, unsigned int *buffer_size,
				 unsigned int *index)
{
	char *string = va_arg(ap, char *);
	char *cpy_str;
	int str_len, i;

	if (string == NULL)
		return (buffer);
	str_len = _strlen(string);
	cpy_str = malloc(str_len + 1);
	if (cpy_str == NULL)
		return (buffer);
	_strcpy(cpy_str, string);
	cpy_str[str_len] = '\0';
	rot13(cpy_str);
	buffer = _realloc(buffer, *buffer_size, *buffer_size + str_len);
	*buffer_size += str_len;
	for (i = 0; cpy_str[i] != '\0'; i++)
	{
		buffer[(*index)++] = cpy_str[i];
	}
	(*index)--;
	free(cpy_str);
	return (buffer);
}

