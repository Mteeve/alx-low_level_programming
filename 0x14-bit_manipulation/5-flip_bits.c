#include "main.h"

/**
* flip_bits - Counts the number of bits that need to be changed to get from
*             one number to another.
*
* @n: The first number.
* @m: The second number.
*
* Return: The number of bits that need to be changed.
*/

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
unsigned long int exclusive = n ^ m;
unsigned int count = 0;

while (exclusive)
{
count += exclusive & 1;
exclusive >>= 1;
}

return (count);
}
