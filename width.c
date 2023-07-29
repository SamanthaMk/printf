#include "main.h"

/**
 * get_print_width - Calculates the width for printing
 * @format_str: Formatted string in which to print the arguments.
 * @index: List of arguments to be printed.
 * @arg_list: list of arguments.
 *
 * Return: width.
 */

int get_print_width(const char *format_str, int *index, va_list arg_list)
{
	int current_index;
	int width = 0;

	for (current_index = *index + 1; format_str[current_index] != '\0'; current_index++)
	{
		if (digit_check(format_str[current_index]))
		{
			width *= 10;
			width += format_str[current_index] - '0';
		}
		else if (format_str[current_index] == '*')
		{
			current_index++;
			width = va_arg(arg_list, int);
			break;
		}
		else
			break;
	}

	*index = current_index - 1;

	return (width);
}
