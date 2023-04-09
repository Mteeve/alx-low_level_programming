#include "main.h"

/**
* print_binary - Prints the binary representation of a decimal number.
*
* @n: The decimal number to print in binary.
*/
void print_binary(unsigned long int n)
{
int i;
int printed = 0;

for (i = 63; i >= 0; i--)
{
if ((n >> i) & 1)
{
_putchar('1');
printed = 1;
}
else if (printed)
{
_putchar('0');
}
}

if (!printed)
{
_putchar('0');
}
}
