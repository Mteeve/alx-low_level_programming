#include "main.h"
#include <stddef.h>

/**
* binary_to_uint - Convert a binary number string to an unsigned integer.
*
* @b: A pointer to the binary number string.
*
* Return: The unsigned integer representation of the binary number string.
*         If the string is NULL or contains invalid characters, return 0.
*/

unsigned int binary_to_uint(const char *b)
{
unsigned int decimal = 0;
int i;

if (b == NULL)
return (0);

for (i = 0; b[i] != '\0'; ++i)
{
if (b[i] < '0' || b[i] > '1')
return (0);

decimal = decimal * 2 + (b[i] - '0');
}

return (decimal);
}
