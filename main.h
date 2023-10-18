#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>

/**
 * struct c_type - struct for fuction and it's specifier
 * @c: character
 * @spec: function that return poiner to char
 *
 */
typedef struct c_type
{
	char c;
	char *(*spec)(char *, va_list, unsigned int *, unsigned int *);
} f_list;


int _printf(const char *format, ...);
int _strlen(const char *str);
void *_memcpy(char *dest, char *src, unsigned int n);
char *char_handler(char *buffer, va_list ap
		, unsigned int *buffer_size, unsigned int *index);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *string_handler(char *buffer, va_list ap, unsigned int *buffer_size,
					unsigned int *index);
char *num_handler(char *buffer, va_list ap, unsigned int *buffer_size,
					unsigned int *index);
char *u_num_handler(char *buffer, va_list ap, unsigned int *buffer_size,
					unsigned int *index);
char *binary_handler(char *buffer, va_list ap, unsigned int *buffer_size,
					unsigned int *index);
char *octal_handler(char *buffer, va_list ap, unsigned int *buffer_size,
					unsigned int *index);
char *hexadecimal_handler(char *buffer, va_list ap, unsigned int *buffer_size,
					unsigned int *index);
char *Hexadecimal_handler(char *buffer, va_list ap, unsigned int *buffer_size,
					unsigned int *index);
char *rev_string(char *buffer, va_list ap, unsigned int *buffer_size,
				unsigned int *index);
char *rot13_handler(char *buffer, va_list ap, unsigned int *buffer_size,
				 unsigned int *index);
char *address_handler(char *buffer, va_list ap, unsigned int *buffer_size, 
                    unsigned int *index);
char *non_printable(char *buffer, va_list ap, unsigned int *buffer_size, 
                    unsigned int *index);
int square10(int n);
void reverse_array(char *a, int n);
char *rot13(char *s);
char *_strcpy(char *dest, char *src);
void print_buffer(char *str);
char *c_hex(int num, char *tmp);

#endif
