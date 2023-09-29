#include "main.h"

/**
 * get_endianness -  a function that checks the endianness.
 *
 * Return: 0 or 1
 */

int get_endianness(void)
{
	unsigned int g;
	char *e;

	g = 1;
	e = (char *) &g;

	return ((int)*e);
}
