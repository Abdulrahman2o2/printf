#include "main.h"

/**
 * is_printable - Determines if a character is printable.
 * @c: The character to be checked.
 *
 * Return: 1 if c is a printable character, 0 otherwise.
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}
/**
 * append_hexa_code - Appends the ASCII value in hexadecimal format to buffer.
 * @buffer: Array of characters to store the result.
 * @i: Index at which to start appending in the buffer.
 * @ascii_code: The ASCII code to be converted to hexadecimal.
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}
/**
 * is_digit - Checks if a character is a digit.
 * @c: The character to be examined.
 *
 * Return: 1 if c is a digit, 0 otherwise.
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}
/**
 * convert_size_number - Converts a number to the specified size.
 * @num: The number to be converted.
 * @size: The desired target size for the conversion.
 *
 * Return: The converted value of num..
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}
/**
 * convert_size_unsgnd - Adjusts the size of an unsigned number.
 * @num: The unsigned number to be resized.
 * @size: The target size for the number's new type.
 *
 * Return: The resized value of num.
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
