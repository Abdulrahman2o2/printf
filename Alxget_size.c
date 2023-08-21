#include "main.h"

/**
 * get_size - Determines the size modifier for argument casting
 * @format: Formatted string containing the argument specification
 * @i: Index in the format string
 *
 * This function parses the format string to identify the size modifier
 * for casting the argument. Size modifiers include 'l' for long and 'h'
 * for short.
 *
 * Return: The size modifier for argument casting
 */
int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size);
}

