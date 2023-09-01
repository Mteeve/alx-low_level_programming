#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index in a decimal number.
 *
 * @num: The decimal number to search.
 * @index: The index of the bit.
 *
 * Return: The value of the bit at the given index, or -1 if the index is invalid.
 */
int get_bit(unsigned long int num, unsigned int index)
{
    int bit_value;

    if (index > 63)
    {
        return (-1);
    }

    bit_value = (num >> index) & 1;

    return (bit_value);
}
