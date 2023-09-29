#include "main.h"

/**
 * clear_bit - sets bit to 0
 * @n: this is a pointer
 * @index: the index
 *
 * Return: 1 or -1
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int b;

	if (index > 63)
		return (-1);

	b = 1 << index;

	if (*n & b)
		*n ^= b;

	return (1);
}
