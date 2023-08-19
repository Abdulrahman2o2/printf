#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1   /* Left-justify */
#define F_PLUS 2   /* Print a plus sign for positive numbers */
#define F_ZERO 4 /* Pad with zeros */
#define F_HASH 8   /* Prefix with 0, 0x, or 0X for octal or hexadecimal */
#define F_SPACE 16  /* Precede positive numbers with a space */

/* SIZES */
#define S_LONG 2  /* Long size modifier */
#define S_SHORT 1  /* Short size modifier */

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);
