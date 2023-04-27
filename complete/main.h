#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BYTE_SIZE 1024

/* FLAGS */
#define MINUS_SIGN 1
#define PLUS_SIGN 2
#define ZERO 4
#define HASH_SIGN 8
#define SPACE 16

/* SIZES */
#define LONG 2
#define SHORT 1

/**
 * struct format - data type of format
 * @fmt: format.
 * @fn: associated function.
 */

typedef struct format
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
} format_t;

int _printf(const char *format, ...);
int _print(const char *output, int *i, va_list args, char buffer[],
		int flags, int wid, int prec, int size);

/* specifier functions */
int fetch_flags(const char *format, int *i);
int fetch_width(const char *format, int *i, va_list args);
int fetch_precision(const char *format, int *i, va_list args);
int fetch_size(const char *format, int *i);

/* Functions to print numbers */
int print_octal(va_list args, char buffer[], int flag, int wid,
		int prec, int size);

int print_hexadecimal(va_list args, char buffer[], int flag, int wid,
		int prec, int size);

int print_unsigned_nums(va_list args, char buffer[], int flag, int wid,
		int prec, int size);

int print_binary(va_list args, char buffer[], int flag, int wid,
		int prec, int size);

int print_integers(va_list args, char buffer[], int flag, int wid,
		int prec, int size);

int print_hex_upper(va_list args, char buffer[], int flag, int wid,
		int prec, int size);

int print_hex_result(va_list args, char hex_value[], char buffer[], int flag,
		char flag_char, int wid, int prec, int size);

/* Function to print non printable characters */
int print_non_printable(va_list args, char buffer[], int flag, int wid,
		int prec, int size);

int print_pointer(va_list args, char buffer[], int flag, int wid,
		int prec, int size);

int print_reversal(va_list args, char buffer[], int flag, int wid,
		int prec, int size);

/*return a string in rot 13*/
int print_rot13(va_list args, char buffer[], int flag, int wid,
		int prec, int size);

int handles_write_char(char c, char buffer[], int flags, int wid,
		int prec, int size);

int output_numbers(int is_neg, int ind, char buffer[], int flag, int wid,
		int prec, int size);

int write_num(int ind, char buffer[], int flags, int wid, int prec,
			int len, char padd, char extra_char);

int write_pointer(char buffer[], int ind, int len, int wid, int flag,
		char padd, char extra_char, int padd_start);

int write_unsigned_val(int is_neg, int ind, char buffer[], int flag,
		int wid, int prec, int size);

/*** Functions that prints char, string, percent ***/
int print_percent(va_list args, char buffer[], int flag, int wid,
		int prec, int size);
int print_str(va_list args, char buffer[], int flag, int wid,
		int prec, int size);
int print_char(va_list args, char buffer[], int flag, int wid,
		int prec, int size);

/*** Helper function ***/
int is_char(char);

int append_hexa_code(char, char[], int);

int is_digit(char);

long int convert_int_size(long int nums, int size);

long int convert_unsigned_size(unsigned long int nums, int size);

#endif /*MAIN_H*/

