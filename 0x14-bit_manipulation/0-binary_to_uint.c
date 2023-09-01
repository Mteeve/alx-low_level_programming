#include "main.h"
#include <stddef.h>

/**
 * binary_to_uint - Converts a binary number string to an unsigned integer.
 *
 * @b: A pointer to the binary number string.
 *
 * Return: The converted unsigned integer.
 *         If the string is NULL or contains invalid characters, return 0.
 */
unsigned int binary_to_uint(const char *b)
{
    unsigned int result = 0;
    int index;

    if (b == NULL)
        return (0);

    for (index = 0; b[index] != '\0'; ++index)
    {
        if (b[index] != '0' && b[index] != '1')
            return (0);

        result = result * 2 + (b[index] - '0');
    }

    return (result);
}
