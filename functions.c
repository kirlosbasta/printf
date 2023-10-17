#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
/**
 * _strlen - Return the length of a string
 * @str: Pointer to string
 *
 * Return: The length
 */

int _strlen(const char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * _realloc - reallocates a memory block
 * @ptr: pointer to the old memory
 * @old_size: The old memory size
 * @new_size: The new memory size
 *
 * Return: pointer to the new memory block in success or null in failure
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr = NULL;

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
	{
		return (ptr);
	}
	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		return (new_ptr);
	}

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
	{
		return (NULL);
	}
	_memcpy(new_ptr, ptr, old_size);
	free(ptr);
	return (new_ptr);
}

/**
 * _memcpy - copies the memory area from src to dest until n is reached
 * @dest: pointer to the destination pointer
 * @src: pointer to sourc pointer
 * @n: The size of bytes to copy from src
 * Return: pointer to dest
 */

void *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		*(dest + i) = *(src + i);
	}
	*(dest + i) = '\0';
	return (dest);
}

/**
 * square10 - Return the n square of 10
 * @n: number of 10 square
 *
 * Return: N square of 10
 */

int square10(int n)
{
	int sq = 1;

	n -= 1;
	while (n > 0)
	{
		sq *= 10;
		n -= 1;
	}
	return (sq);
}

/**
 * reverse_array - revers the array from bach to end
 * @a: pointer to array
 * @n: number of element
 * Return Notiing
 */
void reverse_array(char *a, int n)
{
	int i;
	int temp;

	for (i = 0; i < n / 2; i++)
	{
		temp = a[i];
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = temp;
	}
}
