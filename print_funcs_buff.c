#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * print_c - Copy a character into the buffer & print if buffer is full
 * @args: Va_list of all given arguments to _printf
 * @buffer: The buffer being copied to to print
 * @buflen: The current length of the buffer aka number of characters in buffer
 * @bufpos: Current position, or index, inside the buffer
 *
 * Return: Returns number of characters copied to buffer, allows for _printf to
 * return proper number of characters printed
 */
int print_c(va_list args, char buffer[], int *buflen, int *bufpos)
{
	if (*buflen < 1024)
	{
		buffer[*bufpos] = va_arg(args, int);
		*bufpos += 1;
		*buflen += 1;
		if (*buflen == 1024)
			write_buffer(buffer, buflen, bufpos);
	}
	else
	{
		write_buffer(buffer, buflen, bufpos);
		buffer[*bufpos] = va_arg(args, int);
		*bufpos += 1;
		*buflen += 1;
	}
	return (1);
}

/**
 * print_s - Copy a string into the buffer & print if buffer is full
 * @args: Va_list of all given arguments to _printf
 * @buffer: The buffer being copied to to print
 * @buflen: The current length of the buffer aka number of characters in buffer
 * @bufpos: Current position, or index, inside the buffer
 *
 * Return: Returns number of characters copied to buffer, allows for _printf to
 * return proper number of characters printed
 */
int print_s(va_list args, char buffer[], int *buflen, int *bufpos)
{
	char *str;
	int i, chars;

	i = chars = 0;
	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	while (str[i] != '\0')
	{
		buffer[*bufpos] = str[i];
		*bufpos += 1;
		*buflen += 1;
		if (*buflen == 1024)
			write_buffer(buffer, buflen, bufpos);
		i++;
		chars++;
	}
	return (chars);
}

/**
 * print_int - Call the function to copy a number to the buffer
 * @args: Va_list of all given arguments to _printf
 * @buffer: The buffer being copied to to print
 * @buflen: The current length of the buffer aka number of characters in buffer
 * @bufpos: Current position, or index, inside the buffer
 *
 * Return: Returns number of characters copied to buffer, allows for _printf to
 * return proper number of characters printed
 */
int print_int(va_list args, char buffer[], int *buflen, int *bufpos)
{
	int chars;
	int n;

	n = va_arg(args, int);
	chars = print_number(n, buffer, buflen, bufpos);
	return (chars);
}

/**
* print_u - prints the unsigned int
* @args: number to be printed
* @buffer: space used for printing
* @buflen: buffer length
* @bufpos: current buffer index
* Return: numbers of chars written to buffer
**/
int print_u(va_list args, char buffer[], int *buflen, int *bufpos)
{
	unsigned int c;
	int chars;

	c = va_arg(args, unsigned int);
	chars = print_Unum(c, buffer, buflen, bufpos);
	return (chars);
}
