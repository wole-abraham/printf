#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
* print_r - prints the reversed string
* @args: string to be printed
* @buffer: space used for printing
* @buflen: buffer length
* @bufpos: current buffer index
* Return: numbers of chars written to buffer
**/
int print_r(va_list args, char buffer[], int *buflen, int *bufpos)
{
	char *str;
	int i, numChars;

	i = numChars = 0;
	str = va_arg(args, char *);
	if (str == NULL)
		str = "(nil)";
	while (str[i] != '\0')
		i++;
	i--;
	for (; i >= 0; i--, numChars++)
	{
		buffer[*bufpos] = str[i];
		*bufpos += 1;
		*buflen += 1;
		if (*buflen == 1024)
			write_buffer(buffer, buflen, bufpos);
	}
	return (numChars);
}
/**
* print_R - prints the rot13'ed string
* @args: string to be printed
* @buffer: space used for printing
* @buflen: buffer length
* @bufpos: current buffer index
* Return: numbers of chars written to buffer
**/
int print_R(va_list args, char buffer[], int *buflen, int *bufpos)
{
	char *str, temp;
	int i, numChars;

	i = numChars = 0;
	str = va_arg(args, char *);
	if (str == NULL)
		str = "(nil)";
	while (str[i] != '\0')
	{
		temp = str[i];
		if ((temp >= 'A' && temp <= 'M') ||
		    (temp >= 'a' && temp <= 'm'))
			temp += 13;
		else if ((temp >= 'N' && temp <= 'Z')
			 || (temp >= 'n' && temp <= 'z'))
			temp -= 13;

		buffer[*bufpos] = temp;
		*bufpos += 1;
		*buflen += 1;
		if (*buflen == 1024)
			write_buffer(buffer, buflen, bufpos);
		i++, numChars++;
	}
	return (numChars);
}
/**
* print_p - prints the address of a variable
* @args: number to be printed
* @buffer: space used for printing
* @buflen: buffer length
* @bufpos: current buffer index
* Return: numbers of chars written to buffer
**/
int print_p(va_list args, char buffer[], int *buflen, int *bufpos)
{
	char *str;
	int i, numChars;
	size_t add;

	add = (size_t)va_arg(args, void *);
	str = size_tHex('x', add);
	if (str == NULL)
		return (0);
	i = numChars = 0;
	buffer[*bufpos] = '0';
	numChars++;
	*bufpos += 1;
	*buflen += 1;
	if (*buflen == 1024)
		write_buffer(buffer, buflen, bufpos);
	buffer[*bufpos] = 'x';
	numChars++;
	*bufpos += 1;
	*buflen += 1;
	if (*buflen == 1024)
	write_buffer(buffer, buflen, bufpos);
	while (str[i] != '\0')
	{
		buffer[*bufpos] = str[i];
		*bufpos += 1;
		*buflen += 1;
		if (*buflen == 1024)
			write_buffer(buffer, buflen, bufpos);
		i++, numChars++;
	}
	free(str);
	return (numChars);
}
