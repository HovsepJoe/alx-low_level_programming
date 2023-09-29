#include "main.h"

/**
 * print_binary - this prints the binary rep_num
 * @n: The number printed in binary
 *
 * Description: The function above prints the binary
 * representation of a number
 * Return: null
 */

void print_binary(unsigned long int n)
{
	if (n >> 0)
	{
		if (n >> 1)
			print_binary(n >> 1);
		_putchar((n & 1) + '0');
	}
	else
	{
		_putchar('0');
	}
}
