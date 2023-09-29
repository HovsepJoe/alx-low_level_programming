#include "main.h"

/**
 * binary_to_uint - converts binary to unsigne int
 * @b: This a pointer pointing to string '0' and '1'
 *
 * Description: The above function converts a binary number to an unsigned int
 * where b is pointing to a string of 0 and 1 chars
 * Return: the converted number, or 0 if
 * one or more chars in the string b that is not 0 or 1
 * b is NULL
 */

unsigned int binary_to_uint(const char *b);
{
	unsigned int ui;
	int lnt, base_two;

	if (!b)
		return (0);

	ui = 0;

	for (lnt = 0; b[lnt] != '\0'; lnt++)
		;

	for (lnt--, base_two = 1; lnt >= 0; lnt--, binry *= 2)
	{
		if (b[lnt] != '0' && b[lnt] != '1')
		{
			return (0);
		}

		if (b[lnt] & 1)
		{
			ui += base_two;
		}
	}

	return (ui);
}
