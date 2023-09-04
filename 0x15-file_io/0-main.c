#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - Check the code
 *
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
    ssize_t num_chars;
    
    if (argc != 2)
    {
        dprintf(2, "Usage: %s filename\n", argv[0]);
        exit(1);
    }
    
    num_chars = read_file(argv[1], 114);
    printf("\n(printed chars: %li)\n", num_chars);
    
    num_chars = read_file(argv[1], 1024);
    printf("\n(printed chars: %li)\n", num_chars);
    
    return (0);
}
