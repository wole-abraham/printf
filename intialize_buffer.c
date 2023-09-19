#include "main.h"

/**
 * initialize_buffer - Fill the buffer with null characters for
 * sake of proper write use
 * @buffer: The buffer that needs to be initialized
 */
void initialize_buffer(char buffer[])
{
	int i;

	i = 0;
	while (i < 1024)
	{
		buffer[i] = 0;
		i++;
	}
	buffer[i] = '\0';
}
