#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define FIELD_BUF_SIZE 50
#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2


int _putchar(int c);
int _puts(char *str);

int _printf(const char *format, ...);

/**
 * struct parameters - struct for parameters
 *
 * @unsign: flag for unsigned value
 * @plus_flag: flag for if plus flag is specified
 * @space_flag: flag for if space flag is specified
 * @hashtag_flag: flag for if hash tag flag is specified
 * @zero_flag: flag for if zero flag is specified
 * @minus_flag: flag for if minus flag is specified
 * @width: width of the field
 * @precision: precision
 * @h_modifier: if the h modifier is specified
 * @l_modifier: if the l modifier is specified
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
	unsigned int precision;
	unsigned int h_modifier : 1;
	unsigned int l_modifier : 1;
} params_t;

/**
 * struct specifier - Struct for specifiers
 *
 * @specifier: format specifier
 * @f: the function associated
 */

typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

/* Conversion Specifiers */
int print_char(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);
int print_S(va_list ap, params_t *params);
int print_rev(va_list ap, params_t *params);
int print_rot13(va_list ap, params_t *params);
int print_octal(va_list ap, params_t *params);
int print_binary(va_list ap, params_t *params);
int print_hex(va_list ap, params_t *params);
int print_HEX(va_list ap, params_t *params);
int print_unsigned(va_list ap, params_t *params);
int print_address(va_list ap, params_t *params);

/* Special printf functions handlers */
int (*get_specifier(char *s))(va_list ap, params_t *params);
int get_print_func(char *s, va_list ap, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list ap);

/* Function for printing instructions */
int print_from_to(char *start, char *stop, char *except);

/* Functions for printing numbers */
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);

char *convert(long int num, int base, int flags, params_t *params);

char *get_precision(char *p, params_t *params, va_list ap);
/* Function */
void init_params(params_t *params, va_list ap);

#endif

