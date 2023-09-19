#include "main.h"

/**
 * print_number - Copy the given int one digit at a time to the buffer to print
 * @n: The integer to print
 * @buffer: Buffer beign copied to to print
 * @buflen: Length of the buffer, aka number of characters in buffer
 * @bufpos: Position in the buffer
 *
 * Return: Number of characters printed
 */
int print_number(int n, char buffer[], int *buflen, int *bufpos)
{
	int chars;
	int sign_print;

	chars = sign_print = 0;
	if (n == 0)
	{
		buffer[*bufpos] = '0';
		*bufpos += 1;
		*buflen += 1;
		if (*buflen == 1024)
			write_buffer(buffer, buflen, bufpos);
		return (1);
	}
	else if (n > 0)
		n *= -1;
	else
	{
		buffer[*bufpos] = '-';
		*bufpos += 1;
		*buflen += 1;
		if (*buflen == 1024)
			write_buffer(buffer, buflen, bufpos);
		sign_print = 1;
	}
	if ((n / 10) != 0)
	{
		chars = print_number(((n / 10) * -1), buffer, buflen, bufpos);
	}
	buffer[*bufpos] = (n % 10) * -1 + '0';
	*bufpos += 1;
	*buflen += 1;
	if (*buflen == 1024)
		write_buffer(buffer, buflen, bufpos);
	if (sign_print > 0)
		chars += sign_print;
	chars++;
	return (chars);
}

/**
 * print_Unum - Copy the given unsigned integer to the buffer to print
 * @n: Integer to copy
 * @buffer: Buffer to copy to
 * @buflen: Current length of buffer, # of characters in buffer
 * @bufpos: Current position in the buffer
 *
 * Return: Number of characters printed
 */
int print_Unum(unsigned int n, char buffer[], int *buflen, int *bufpos)
{
	int numChars;

	numChars = 0;
	if (n == 0)
	{
		buffer[*bufpos] = '0';
		*bufpos += 1;
		*buflen += 1;
		if (*buflen == 1024)
			write_buffer(buffer, buflen, bufpos);
		return (1);
	}
	if ((n / 10) != 0)
		numChars = print_Unum((n / 10), buffer, buflen, bufpos);
	buffer[*bufpos] = (n % 10) + '0';
	*bufpos += 1;
	*buflen += 1;
	if (*buflen == 1024)
		write_buffer(buffer, buflen, bufpos);
	numChars++;
	return (numChars);
}
