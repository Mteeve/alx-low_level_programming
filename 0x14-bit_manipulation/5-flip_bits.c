#include "main.h"

/**
 * flip_bits - Counts the number of bits to change
 * to get from one number to another.
 *
 * @num1: First number.
 * @num2: Second number.
 *
 * Return: Number of bits to change.
 */
unsigned int flip_bits(unsigned long int num1, unsigned long int num2)
{
    int i, count = 0;
    unsigned long int current;
    unsigned long int xor_result = num1 ^ num2;

    for (i = 63; i >= 0; i--)
    {
        current = xor_result >> i;
        if (current & 1)
        {
            count++;
        }
    }

    return (count);
}
