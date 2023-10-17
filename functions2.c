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
