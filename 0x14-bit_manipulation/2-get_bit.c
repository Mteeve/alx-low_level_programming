#include "main.h"
#include <stdio.h>

/**
* get_bit - Returns the value of a bit at a given index in a binary number.
*
* @n: The binary number to search.
* @index: The index of the bit to retrieve.
*
* Return: The value of the bit at the given index, or -1 if the index is
*         out of range.
*/

int get_bit(unsigned long int n, unsigned int index)
{
int bit_val;
if (index >= sizeof(unsigned long int) * 8)
{
return (-1);
}

bit_val = (n >> index) & 1;

return ((bit_val) ? 1 : 0);
}
