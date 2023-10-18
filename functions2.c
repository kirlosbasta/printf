#include "main.h"

/**
 * rot13 - encode using rot13 encoding
 * @s: pointer to string
 * Return: pointer to string
 */

char *rot13(char *s)
{
	int i, j;
	char r1[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
		     'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y',
		     'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
		     'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y',
		     'Z'};
	char r2[] = {'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y',
		     'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
		     'm', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y',
		     'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
		     'M'};

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; r1[j] != '\0'; j++)
		{
			if (s[i] == r1[j])
			{
				s[i] = r2[j];
				break;
			}
		}
	}
	return (s);
}

/**
 * *_strcpy - copy the content of src to dest
 * @dest: pointer to the destination
 * @src: pointer to source
 * Return: Pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	char *destptr = dest;
	char *srcptr = src;

	while (*srcptr != '\0')
	{
		*destptr = *srcptr;
		destptr++;
		srcptr++;
	}
	*destptr = '\0';
	return (dest);
}

/**
 * print_buffer - Print the buffer
 * @str: pointer to string
 * 
 * Return: Nothing
 */

void print_buffer(char *str)
{
	int len = _strlen(str);

	write(1, str, len);
}

/**
 * c_hex - convert a number to hex
 * @num: decimal number
 * @tmp: Conatiner to a string
 * 
 * Return: Pointer to string
 */

char *c_hex(int num, char *tmp)
{
	char hex[] = "0123456789ABCDEF";
	int i = 0, j = 0;
	char c[3];

	if (num < 16)
	{
		tmp[i++] = '0';
		tmp[i++] = hex[num];
		tmp[i] = '\0';
		return (tmp);
	}
	else
	{
		while (num > 0)
		{
			c[i++] = (num % 16) + '0';
			num /= 16;
		}
		c[i] = '\0';
	}
	for (; c[i - 1] > 0; i--)
	{
		tmp[j++] = c[i];
	}
	tmp[j] = '\0';
	return (tmp);
}