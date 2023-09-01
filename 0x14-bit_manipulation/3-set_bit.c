#include "main.h"

/**
 * set_bit - Sets a bit at a given index to 1.
 *
 * @num: Pointer to the number to change.
 * @index: Index of the bit to set to 1.
 *
 * Return: 1 for success, -1 for failure.
 */
int set_bit(unsigned long int *num, unsigned int index)
{
    if (index > 63)
    {
        return (-1);
    }

    *num = ((1UL << index) | *num);

    return (1);
}
