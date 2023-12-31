#include "main.h"

/**
 * handle - Prints an argument based on its type
 * @format_str: Formatted string in which to print the arguments.
 * @arg_list: List of arguments to be printed.
 * @index: ind.
 * @output_buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @arg_size: Size specifier
 * Return: 1 or 2;
 */

int handle(const char *format_str, int *index, va_list arg_list, char output_buffer[],

        int flag, int range, int pre, int area)

{

	int j, unknow_length = 0, printed_chars = -1;

	FormatEntry format_types[] = {

		{'c', prints_char1}, {'s', prints_string2}, {'%', prints_per_cent},

		{'i', prints_int}, {'d', prints_int}, {'b', prints_binary},

		{'u', prints_unsign_num}, {'o', print_octa}, {'x', prints_hexa},

		{'X', print_up_hexa}, {'p', prints_point}, {'S', prints_none_print},

		{'r', prints_rev}, {'R', print_rot13strng}, {'\0', NULL}

	};

	for (j = 0; format_types[j].format != '\0'; j++)

		if (format_str[*index] == format_types[j].format)

			return (format_types[j].fn(arg_list, output_buffer, flag, range, pre, area));

	if (format_types[j].format == '\0')
	{
		if (format_str[*index] == '\0')
			return (-1);

		unknow_length += write(1, "%%", 1);

		if (format_str[*index - 1] == ' ')
			unknow_length += write(1, " ", 1);
		else if (range)
		{
			--(*index);
			while (format_str[*index] != ' ' && format_str[*index] != '%')
				--(*index);

			if (format_str[*index] == ' ')
				--(*index);

			return (1);
		}

		unknow_length += write(1, &format_str[*index], 1);
		return (unknow_length);
	}

	return (printed_chars);

}
