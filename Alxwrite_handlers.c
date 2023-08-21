#include "main.h"

/************************* WRITE HANDLE *************************/
/**
 * handle_write_char - Handles printing of a single character
 * @c: The character to be printed
 * @buffer: Buffer array to handle print
 * @flags: Flag to calculate active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * This function handles printing a single character, considering
 * width, precision, and padding specifications as specified by flags.
 *
 * Return: Number of characters printed
 */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size)
{ /* char is stored at left and paddind at buffer's right */
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = padd;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}
/**
 * write_number - Handles printing of signed numbers
 * @is_negative: Indicator if the number is negative
 * @ind: Index where the number starts in the buffer
 * @buffer: Buffer array to handle print
 * @flags: Flag to calculate active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * This function handles printing of signed numbers, considering
 * alignment, width, precision, and padding specifications.
 *
 * Return: Number of characters printed
 */
int write_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buffer, flags, width, precision,
		length, padd, extra_ch));
}

