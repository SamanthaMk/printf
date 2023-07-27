#include "main.h"

/**
 * get_arg_size - Calculates the size to cast the argument
 * @format_str: Formatted string in which to print the arguments
 * @index: List of arguments to be printed.
 *
 * Return: Precision(Argument size).
 */

int get_arg_size(const char *format_str, int *index)
{
	int current_index = *index + 1;
	int arg_size = 0;

	if (format_str[current_index] == 'l')
		size = S_LONG;
	else if (format_str[current_index] == 'h')
		size = S_SHORT;

	if (arg_size == 0)
		*index = current_index - 1;
	else
		*index = current_index;

	return (arg_size);
}
