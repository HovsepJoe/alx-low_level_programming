#include "main.h"

/**
 * binary_to_uint - converts binary to unsigne int
 * @b: This a pointer pointing to string '0' and '1'
 *
 * Description: The above function converts a binary number to an unsigned int
 * where b is pointing to a string of 0 and 1 chars
 * Return: the converted number, or 0 if
 * there is one or more chars in the string b that is not 0 or 1
 * b is NULL
 */

unsigned int binary_to_uint(const char *b);
{
        unsigned int h = 0;
        unsigned int bit_value = 1;

        if (b == NULL)
                return (0);
        int i = 0;
        while (b[i] != '\0')
        {
                if (b[i] == '0')
                {
                        h <<= 1;
                }
                else if (b[i] == '1')
                {
                        h = (h << 1) | 1;
                }
                else
		{
			return (0);
		}
		i++;
	}
	return (h);
}
