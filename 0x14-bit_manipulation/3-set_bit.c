#include "main.h"

/**
* set_bit - Sets a bit at a given index to 1 in a decimal number.
*
* @n: A pointer to the decimal number to modify.
* @index: The index of the bit to set to 1.
*
* Return: 1 for success, -1 for failure (if the index is greater than 63).
*/

int set_bit(unsigned long int *n, unsigned int index)
{
if (index > 63)
return (-1);

*n |= (1UL << index);
return (1);
}
