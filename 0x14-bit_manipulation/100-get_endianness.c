#include "main.h"

/**
 * get_endianness - Checks the endianness of a machine.
 *
 * Return: 0 if the machine is big endian, 1 if it is little endian.
 */
int get_endianness(void)
{
    unsigned int num = 1;
    char *byte = (char *)&num;

    return (*byte);
}
