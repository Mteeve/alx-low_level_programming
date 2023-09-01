#include "main.h"

/**
 * print_binary - Prints the binary representation of a decimal number.
 *
 * @n: The decimal number to print in binary.
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1;
	int size = sizeof(n) * 8; /* Number of bits in unsigned long int */

	/* Find the most significant bit */
	while (mask << 1 <= n)
		mask <<= 1;

	/* Print the binary representation */
	while (mask > 0)
	{
		if (n & mask)
			_putchar('1');
		else
			_putchar('0');

		mask >>= 1;
	}

	if (n == 0)
		_putchar('0');
}
