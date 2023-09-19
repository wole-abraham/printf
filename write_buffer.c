#include <unistd.h>
#include "main.h"

/**
 * write_buffer - Print out the buffer of all characters to print
 * @buffer: The buffer with the string needed to print
 * @buflen: Pointer to the length of buffer
 * @bufpos: Pointer to the postion inside buffer
 */
void write_buffer(char buffer[], int *buflen, int *bufpos)
{
	write(1, buffer, *buflen - 1);
	*bufpos = 0;
	*buflen = 1;
}
