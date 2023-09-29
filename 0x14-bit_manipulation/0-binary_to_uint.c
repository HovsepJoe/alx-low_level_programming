#include "main.h"

/**
 * binary_to_uint - converts binary to unsigne int
 * @b: This a pointer pointing to string '0' and '1'
 *
 * Description: The above function converts a binary number to an unsigned int
 * where b is pointing to a string of 0 and 1 chars
 * Return: unsig int
 */

unsigned int binary_to_uint(const char *b);
{
	unsigned int ui;
	int len, base_two;

	if (!b)
		return (0);

	ui = 0;

	for (len = 0; b[len] != '\0'; len++)
		;

	for (len--, base_two = 1; len >= 0; len--, binry *= 2)
	{
		if (b[len] != '0' && b[len] != '1')
		{
			return (0);
		}

		if (b[len] & 1)
		{
			ui += base_two;
		}
	}

	return (ui);
}
