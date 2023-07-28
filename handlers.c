#include "main.h"

/************************* WRITE HANDLE *************************/
/**
 * handles_write_chars - Prints a string
 * @ch: char types.
 * @buff: Buffer array to handle print
 * @flag:  Calculates active flags.
 * @range: get width.
 * @pre: precision specifier
 * @area: Size specifier
 *
 * Return: Number of chars printed.
 */
int handles_write_chars(char ch, char buff[],
	int flag, int range, int pre, int area)
{
	int j = 0;
	char padding = ' ';

	VAR(pre);
	VAR(area);

	if (flag & FL_ZERO)
		padding = '0';

	buff[j++] = ch;
	buff[j] = '\0';

	if (range > 1)
	{
		buff[BUFF_SIZE - 1] = '\0';
		for (j = 0; j < range - 1; j++)
			buff[BUFF_SIZE - j - 2] = padding;

		if (flag & FL_MINUS)
			return (write(1, &buff[0], 1) +
					write(1, &buff[BUFF_SIZE - j - 1], range - 1));
		else
			return (write(1, &buff[BUFF_SIZE - j - 1], range - 1) +
					write(1, &buff[0], 1));
	}

	return (write(1, &buff[0], 1));
}

/************************* WRITE NUMBER *************************/
/**
 * write_numbers - Prints a string
 * @is_nega: Lista of arguments
 * @index: char types.
 * @buff: Buffer array to handle print
 * @flag:  Calculates active flags
 * @range: get width.
 * @pre: precision specifier
 * @area: Size specifier
 *
 * Return: Number of chars printed.
 */
int write_numbers(int is_nega, int index, char buff[],
	int flag, int range, int pre, int area)
{
	int len = BUFF_SIZE - index - 1;
	char padding = ' ', extra_char = 0;

	UNUSED(area);

	if ((flag & FL_ZERO) && !(flag & FL_MINUS))
		padding = '0';
	if (is_nega)
		extra_char = '-';
	else if (flag & FL_PLUS)
		extra_char = '+';
	else if (flag & FL_SPACE)
		extra_char = ' ';

	return (write_nums(index, buff, flag, range, pre,
	len, padding, extra_char));
}
/**
 * write_nums - Write a numbers using a bufffer
 * @index: Index at which the number starts on the buffer
 * @buff: Buffer
 * @flag: Flags
 * @range: width
 * @pre: Precision specifier
 * @len: Number length
 * @padding: Padding char
 * @extra_char: Extra char
 *
 * Return: Number of printed chars.
 */
int write_nums(int index, char buff[],
		int flag, int range, int pre,
		int len, char padding, char extra_char)
{
	int j, padding_start = 1;

	if (pre == 0 && index == BUFF_SIZE - 2 && buff[index] == '0' && range == 0)
		return (0);
	if (pre == 0 && index == BUFF_SIZE - 2 && buff[index] == '0')
		buff[index] = padding = ' ';
	if (pre > 0 && pre < len)
		padding = ' ';
	while (pre > len)
		buff[--index] = '0', len++;
	if (extra_char != 0)
		len++;
	if (range > len)
	{
		for (j = 1; j < range - len + 1; j++)
			buff[j] = padding;
		buff[j] = '\0';
		if (flag & FL_MINUS && padding == ' ')
		{
			if (extra_char)
				buff[--index] = extra_char;
			return (write(1, &buff[index], len) + write(1, &buff[1], j - 1));
		}
		else if (!(flag & FL_MINUS) && padding == ' ')
		{
			if (extra_char)
				buff[--index] = extra_char;
			return (write(1, &buff[1], j - 1) + write(1, &buff[index], len));
		}
		else if (!(flag & FL_MINUS) && padding == '0')
		{
			if (extra_char)
				buff[--padding_start] = extra_char;
			return (write(1, &buff[padding_start], j - padding_start) +
					write(1, &buff[index], len - (1 - padding_start)));
		}
	}
	if (extra_char)
		buff[--index] = extra_char;
	return (write(1, &buff[index], len));
}

/**
 * write_unsigned - Writes an unsigned number
 * @is_nega: Number indicating if the num is negative
 * @index: Index at which the number starts in the buffer
 * @buff: Array of chars
 * @flag: Flags specifiers
 * @range: Width specifier
 * @pre: Precision specifier
 * @area: Size specifier
 *
 * Return: Number of written chars.
 */
int write_unsigned(int is_nega, int index,
		char buff[],
		int flag, int range, int pre, int area)
{
	int len = BUFF_SIZE - index - 1, j = 0;
	char padding = ' ';

	UNUSED(is_nega);
	UNUSED(area);

	if (pre == 0 && index == BUFF_SIZE - 2 && buff[index] == '0')
		return (0);
	if (pre > 0 && pre < len)
		padding = ' ';

	while (pre > len)
	{
		buff[--index] = '0';
		len++;
	}

	if ((flag & FL_ZERO) && !(flag & FL_MINUS))
		padding = '0';

	if (range > len)
	{
		for (j = 0; j < area - len; j++)
			buff[j] = padding;

		buff[j] = '\0';

		if (flag & FL_MINUS)
		{
			return (write(1, &buff[index], len) + write(1, &buff[0], j));
		}
		else
		{
			return (write(1, &buff[0], j) + write(1, &buff[index], len));
		}
	}

	return (write(1, &buff[index], len));
}
/**
 * writes_pointers - Write a memory address
 * @buff: Arrays of chars
 * @index: Index at which the number starts in the buffer
 * @len: Length of number
 * @range: Width specifier
 * @flag: Flags specifier
 * @padding: Char representing the padding
 * @extra_char: Char representing extra char
 * @padding_start: Index at which padding should start
 *
 * Return: Number of written chars.
 */
int writes_pointers(char buff[], int index, int len,
	int range, int flag, char padding, char extra_char, int padding_start)
{
	int j;

	if (range > len)
	{
		for (j = 3; j < range - len + 3; j++)
			buff[j] = padding;
		buff[j] = '\0';
		if (flag & FL_MINUS && padding == ' ')
		{
			buff[--index] = 'x';
			buff[--index] = '0';
			if (extra_char)
				buff[--index] = extra_char;
			return (write(1, &buff[index], len) + write(1, &buff[3], j - 3));
		}
		else if (!(flag & FL_MINUS) && padding == ' ')
		{
			buff[--index] = 'x';
			buff[--index] = '0';
			if (extra_char)
				buff[--index] = extra_char;
			return (write(1, &buff[3], j - 3) + write(1, &buff[index], len));
		}
		else if (!(flag & FL_MINUS) && padding == '0')
		{
			if (extra_char)
				buff[--padding_start] = extra_char;
			buff[1] = '0';
			buff[2] = 'x';
			return (write(1, &buff[padding_start], j - padding_start) +
					write(1, &buff[index], len - (1 - padding_start) - 2));
		}
	}
	buff[--index] = 'x';
	buff[--index] = '0';
	if (extra_char)
		buff[--index] = extra_char;
	return (write(1, &buff[index], BUFF_SIZE - index - 1));
}
