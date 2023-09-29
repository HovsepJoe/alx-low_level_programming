#include "main.h"

/**
 * binary_to_uint - converts binary to unsigned int
 * @b: This a pointer pointing to string '0' and '1'
 *
 * Description: The above function converts a binary number to an unsigned int
 * where b is pointing to a string of 0 and 1 chars
 * Return: unsigned int
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int ans;
	int siz, binry;

	if (!b)
		return (0);

	ans = 0;

	for (siz = 0; b[siz] != '\0'; siz++)
		;

	for (siz--, binry = 1; siz >= 0; siz--, binry *= 2)
	{
		if (b[siz] != '0' && b[siz] != '1')
		{
			return (0);
		}

		if (b[siz] & 1)
		{
			ans += binry;
		}
	}

	return (ans);
}