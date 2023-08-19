#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Custom printf function
 * @format: Format string containing text and format specifiers.
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			// Flush buffer if it's full
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			// Print the current character
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			// Flush buffer before processing format specifier
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
size = get_size(format, &i);
++i;
// Handle format specifier and add printed characters to total
printed = handle_print(format, &i, list, buffer,
flags, width, precision, size);
if (printed == -1)
return (-1);
printed_chars += printed;
}
}
// Flush any remaining content in the buffer
print_buffer(buffer, &buff_ind);
va_end(list);
return (printed_chars);
}
