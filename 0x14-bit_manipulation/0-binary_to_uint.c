#include "main.h"
#include <stddef.h>

/**
 * binary_to_uint - Converts a binary number string to an unsigned integer.
 *
 * @binary: A pointer to the binary number string.
 *
 * Return: The unsigned integer representation of the binary number string.
 *         If the string is NULL or contains invalid characters, return 0.
 */
unsigned int binary_to_uint(const char *binary)
{
    unsigned int result = 0;
    int index;

    if (binary == NULL)
        return (0);

    for (index = 0; binary[index] != '\0'; ++index)
    {
        if (binary[index] < '0' || binary[index] > '1')
            return (0);

        result = result * 2 + (binary[index] - '0');
    }

    return (result);

