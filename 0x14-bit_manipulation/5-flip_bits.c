#include "main.h"

/**
 * flip_bits - return the number of bits
 * needed to flip
 * @n: first number
 * @m: second number
 *
 * Return: The number of bits
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int fbits;

	for (fbits = 0; n || m; n >>= 1. m >>= 1)
	{
		if ((n & 1) != (m & 1))
			fbits++;

	}

	return (fbits);
}
