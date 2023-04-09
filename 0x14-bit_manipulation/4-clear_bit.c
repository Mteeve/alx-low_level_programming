#include "main.h"

/**
* clear_bit - Clears the value of a given bit to 0 in a decimal number.
*
* @n: A pointer to the decimal number to modify.
* @index: The index of the bit to clear.
*
* Return: 1 for success, -1 for failure (if the index is greater than 63).
*/

int clear_bit(unsigned long int *n, unsigned int index)
{
if (index > 63)
return (-1);

*n &= ~(1UL << index);
return (1);
}
