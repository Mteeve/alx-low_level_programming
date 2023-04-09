#include "main.h"

/**
* get_endianness - Checks whether the machine is little or big endian.
*
* Return: 0 if the machine is big endian, 1 if it is little endian.
*/

int get_endianness(void)
{
int i = 1;
char *c = (char *) &i;

if (*c)
{
/* The machine is little endian */
return (1);
}
else
{
/* The machine is big endian */
return (0);
}
}
