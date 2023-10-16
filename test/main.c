#include "main.h"
#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */

int main(void)
{
	int len1, len2;

	len1 = _printf("koko %s %s\n", "is awsome", 'f');
	len2 = printf("koko %s %c\n", "is awsome", 'f');
	printf("size of len1 [%d]\nsize of len2[%d]\n", len1, len2);
	return (0);
}
