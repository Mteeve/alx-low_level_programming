#include "main.h"

/**
 * print_binary - Prints the binary representation of a decimal number.
 *
 * @num: The decimal number to print in binary.
 */
void print_binary(unsigned long int num)
{
    int bit_position;
    int is_printed = 0;

    for (bit_position = 63; bit_position >= 0; bit_position--)
    {
        if ((num >> bit_position) & 1)
        {
            _putchar('1');
            is_printed = 1;
        }
        else if (is_printed)
        {
            _putchar('0');
        }
    }

    if (!is_printed)
    {
        _putchar('0');
    }
}
