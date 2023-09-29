#include "main.h"

/**
 * set_bit - this set the value of bit to 1
 * @n: this is a pointer
 * @index: the index of the bit
 * Return: 1 or -1
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int k;

	if (index > 63)
		return (-1);

	k = 1 << index;
	*n = (*n | k);

	return (1);
}
