#include "main.h"

/**
 * printable_check - Evaluates if a char is printable
 * @ch: Char to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int printable_check(char ch)
{
	if (ch >= 32 && ch < 127)
		return (1);

	return (0);
}

/**
 * add_hexa_code - Append ascci in hexadecimal code to buffer
 * @buff: Array of chars.
 * @j: Index at which to start appending.
 * @ascii: ASSCI CODE.
 * Return: Always 3
 */
int add_hexa_code(char ascii, char buff[], int j)
{
	char hexa_num[] = "0123456789ABCDEF";
	if (ascii < 0)
		ascii *= -1;

	buff[j++] = '\\';
	buff[j++] = 'x';

	buff[j++] = hexa_num[ascii / 16];
	buff[j] = hexa_num[ascii % 16];

	return (3);
}

/**
 * digit_check - Verifies if a char is a digit
 * @ch: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int digit_check(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);

	return (0);
}

/**
 * convert_num_size - Casts a number to the specified size
 * @number: Number to be casted.
 * @area: Number indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int convert_num_size(long int number, int area)
{
	if (area == S_LONG)
		return (number);
	else if (area == S_SHORT)
		return ((short)number);

	return ((int)number);
}
/**
 * convert_area_unsigned - Casts a number to the specified size
 * @number: Number to be casted
 * @area: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int convert_area_unsigned(unsigned long int number, int area)
{
	if (area == S_LONG)
		return (number);
	else if (area == S_SHORT)
		return ((unsigned short)number);

	return ((unsigned int)number);
}
