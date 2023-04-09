#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes the char c to stdout
 * @c: The char to print
 *
 * return: 1.
 * on err, -1 is returned, and errno is set.
 */

int _putchar(char c)
{
        return(write(1,&c,1));
}
