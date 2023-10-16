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

	len1 = _printf("%d %s %c\n", 12345, "koko", 'c');
	len2 = printf("%d %s %c\n", 12345, "koko", 'c');
	printf("size of len1 [%d]\nsize of len2[%d]\n", len1, len2);
	return (0);
}
