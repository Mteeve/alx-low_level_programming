#include "main.h"

/**
* getBit - Returns the value of a bit at a given index in a binary number.
*
* @number: The binary number to search.
* @index: The index of the bit to retrieve.
*
* Return: The value of the bit at the given index, or -1 if the index is
*         out of range.
*/

int getBit(int number, int index)
{
if (index < 0 || index >= 32)
{
return (-1);
}

return ((number >> index) & 1);
}
