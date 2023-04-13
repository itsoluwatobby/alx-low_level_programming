#include "main.h"
#include <stdlib.h>
#include <stdio.h>

int get_length(char *s);
char *parse_to_array(int size);
char *iterate_zeroes(char *s);
int get_num(char c);
void get_result(char *prod, char *m, int num, int zero);
void add_nums(char *f_prod, char *n_prod, int new_len);

/**
 * get_length - function that finds the length of a string.
 * @s: given string.
 * Return: string length.
 */

int get_length(char *s)
{
	int length = 0;

	while (*s++)
		length++;

	return (length);
}

/**
 * parse_to_array - function that creates an array of chars
 *		and initializes it with the character 'x'.
 * @size:size of the array.
 * Return: A pointer to the array.
 */
char *parse_to_array(int size)
{
	char *arr;
	int i;

	arr = malloc(sizeof(char) * size);

	if (arr == NULL)
		exit(98);

	for (i = 0; i < (size - 1); i++)
		arr[i] = 'x';

	arr[i] = '\0';

	return (arr);
}

/**
 * iterate_zeroes - function that iterates through a string
 *		of numbers containing leading zeroes until
 *		it hits a non-zero number.
 * @s: string of numbers.
 * Return: pointer to the next non-zero element.
 */

char *iterate_zeroes(char *s)
{
	while (*s && *s == '0')
		s++;

	return (s);
}

/**
 * get_num - function that converts a character to a
 *		corresponding int.
 * @c: given character.
 * Return: The converted int.
 */

int get_num(char c)
{
	int num = c - '0';

	if (num < 0 || num > 9)
	{
		printf("Error\n");
		exit(98);
	}

	return (num);
}

/**
 * get_result - function that Multiplies a string of numbers
 *		by a single digit.
 * @prod: buffer to store result.
 * @m: string of numbers.
 * @num: single number.
 * @zero: number of leading zeroes.
 *
 * Description: If mult contains a non-digit, the function
 *		exits with a status value of 98.
 */

void get_result(char *prod, char *m, int num, int zero)
{
	int m_len, number, tens = 0;

	m_len = get_length(m) - 1;
	m += m_len;

	while (*prod)
	{
		*prod = 'x';
		prod++;
	}

	prod--;

	while (zero--)
	{
		*prod = '0';
		prod--;
	}

	for (; m_len >= 0; m_len--, m--, prod--)
	{
		if (*m < '0' || *m > '9')
		{
			printf("Error\n");
			exit(98);
		}

		number = (*m - '0') * num;
		number += tens;
		*prod = (number % 10) + '0';
		tens = number / 10;
	}

	if (tens)
		*prod = (tens % 10) + '0';
}

/**
 * add_nums - function that dds the numbers stored
 *		in two strings.
 * @f_prod: The buffer storing the running final product.
 * @n_prod: The next product to be added.
 * @new_len: The length of next_prod.
 */

void add_nums(char *f_prod, char *n_prod, int new_len)
{
	int number, tens = 0;

	while (*(f_prod + 1))
		f_prod++;

	while (*(n_prod + 1))
		n_prod++;

	for (; *f_prod != 'x'; f_prod--)
	{
		number = (*f_prod - '0') + (*n_prod - '0');
		number += tens;
		*f_prod = (number % 10) + '0';
		tens = number / 10;

		n_prod--;
		new_len--;
	}

	for (; new_len >= 0 && *n_prod != 'x'; new_len--)
	{
		number = (*n_prod - '0');
		number += tens;
		*f_prod = (number % 10) + '0';
		tens = number / 10;

		f_prod--;
		n_prod--;
	}

	if (tens)
		*f_prod = (tens % 10) + '0';
}

/**
 * main - function that multiplies two positive numbers.
 * @argv: arguments passed.
 * @argc: number of arguments.
 *
 * Description: If the number of arguments is incorrect
 *		or one number contains non-digits, the
 *		function exits with a status of 98.
 * Return: on success (0).
 */
int main(int argc, char *argv[])
{
	char *f_prod, *n_prod;
	int size, i, digit, zero = 0;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	if (*(argv[1]) == '0')
		argv[1] = iterate_zeroes(argv[1]);
	if (*(argv[2]) == '0')
		argv[2] = iterate_zeroes(argv[2]);
	if (*(argv[1]) == '\0' || *(argv[2]) == '\0')
	{
		printf("0\n");
		return (0);
	}

	size = get_length(argv[1]) + get_length(argv[2]);
	f_prod = parse_to_array(size + 1);
	n_prod = parse_to_array(size + 1);

	for (i = get_length(argv[2]) - 1; i >= 0; i--)
	{
		digit = get_num(*(argv[2] + i));
		get_result(n_prod, argv[1], digit, zero++);
		add_nums(f_prod, n_prod, size - 1);
	}
	for (i = 0; f_prod[i]; i++)
	{
		if (f_prod[i] != 'x')
			putchar(f_prod[i]);
	}
	putchar('\n');

	free(n_prod);
	free(f_prod);

	return (0);
}
