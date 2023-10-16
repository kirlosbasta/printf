#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>

int _printf(const char *format, ...);
int _strlen(const char *str);
void *_memcpy(char *dest, char *src, unsigned int n);
char *char_handler(char *buffer, char character
		, unsigned int *buffer_size, unsigned int *index);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *string_handler(char *buffer, char *string, unsigned int *buffer_size,
					unsigned int *index);
char *num_handler(char *buffer, int num, unsigned int *buffer_size,
					unsigned int *index);
int square10(int n);

#endif
