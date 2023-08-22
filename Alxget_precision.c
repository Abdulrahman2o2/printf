#include "main.h"

/**
 * get_precision - Extracts precision value from the format string
 * @format: Formatted string containing the arguments specification
 * @i: Index in the format string
 * @list: List of arguments
 *
 * This function parses the format string to determine the precision
 * for printing. Precision is indicated by a period ('.') followed by
 * numeric digits or an asterisk ('*').
 *
 * Return: The calculated precision value
 */
int get_precision(const char *format, int *i, va_list list)
{
int curr_i = *i + 1;
int precision = -1;
if (format[curr_i] != '.')
return (precision);
precision = 0;
for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
{
if (is_digit(format[curr_i]))
{
precision *= 10;
precision += format[curr_i] - '0';
}
else if (format[curr_i] == '*')
{
curr_i++;
precision = va_arg(list, int);
break;
}
else
break;
}
*i = curr_i - 1;
return (precision);
}

