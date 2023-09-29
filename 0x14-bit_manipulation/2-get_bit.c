#include "main.h"

/**
 * get_bit - This gets the bit value of a  given index
 * @n: the number to extract bit from
 * @index: index of the bit (0-based)
 *
 * Return: The value of the bit at given index or -1
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int i;

	if (n == 0 && index < 64)
		return (0);

	for (i = 0; i <= 63; n >>= 1, i++)
	{
		if (index == i)
		{
			return (n & 1);
		}
	}

	return (-1);
}