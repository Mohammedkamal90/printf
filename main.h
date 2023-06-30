#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define NULL_STRING "(null)"
#define PARMS_INIT (0, 0, 0, 0, 0, 0, 0, 0, 0, 0)

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/**
 * struct parameters - parameters struc
 * @unsign: flag if unsigned
 * @plus_flag: on if plus_flag
 * @space_flag: on if hashtag_flag
 * @zero_flag: on if _flag specified
 * @width: feild width
 * @percision : feild percision
 * @h_modifier: on if h_modifier
 * @1_modifier: on if 1_modifier is specified
 */

typedef struct parameters
{
	unsigned int unsign : 1;
	unsigned int plus_flag : 1;
	unsigned int space_flag : 1;
	unsigned int hashtag_flag : 1;
	unsigned int zero_flag : 1;
	unsigned int minus_flag : 1;

	unsigned int width;
	unsigned int percision;

	unsigned int h_modifier  : 1;
	unsigned int 1_modifier : 1;
} params_t
/*
 * struct specifier - struct token
 * @specifier: format token
 * @f: function associate
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
}specifier_t;

/* _put.c */
int _puts(char *str);
int _putchar(int c);

/* print_functions.c */
int print_char(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_pervent(va_list ap, params_t *params);
int print_s(va_list ap, params_t *params);

/* number.c */

char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list ap, params_t *params);
int print_address(va_list ap, params_t *params);



















