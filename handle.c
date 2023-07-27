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

        int flags, int width, int precision, int arg_size)

{

	int j, unknow_lenth = 0, printed_chars = -1;

	FormatEntry format_types[] = {

		{'c', print_char}, {'s', print_string}, {'%', print_percent},

		{'i', print_int}, {'d', print_int}, {'b', print_binary},

		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},

		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},

		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}

	};

	for (j = 0; format_types[i].format != '\0'; j++)

		if (format_str[*index] == format_types[i].format)

			return (format_types[i].fn(arg_list, output_buffer, flags, width, precision, arg_size));


	if (format_types[i].format == '\0')
	{
		if (format[*index] == '\0')
			return (-1);

		unknow_len += write(1, "%%", 1);

		if (format[*index - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*index);
			while (format[*index] != ' ' && format[*index] != '%')
				--(*index);

			if (format[*index] == ' ')
				--(*index);

			return (1);
		}

		unknow_len += write(1, &format[*index], 1);
		return (unknow_len);
	}

	return (printed_chars);

}
