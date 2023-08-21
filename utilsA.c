#include "main.h"

/**
 * determine_printability - Determines if a character is printable
 * @c: The character to be checked.
 *
 * Return: 1 if c is a printable character, 0 otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}
