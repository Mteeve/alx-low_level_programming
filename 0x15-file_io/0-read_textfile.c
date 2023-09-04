#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
* read_file - Read file and print to STDOUT.
* @file_name: file being read
* @num_chars: number of characters to be read
* Return: actual number of bytes read and printed
*         0 when function fails or file_name is NULL.
*/
ssize_t read_file(const char *file_name, size_t num_chars)
{
    char *buffer;
    ssize_t file_descriptor;
    ssize_t bytes_read;
    ssize_t bytes_written;

    file_descriptor = open(file_name, O_RDONLY);
    if (file_descriptor == -1)
        return (0);

    buffer = malloc(sizeof(char) * num_chars);
    bytes_read = read(file_descriptor, buffer, num_chars);
    bytes_written = write(STDOUT_FILENO, buffer, bytes_read);

    free(buffer);
    close(file_descriptor);

    return (bytes_written);
}

/**
* main - Entry point
*
* Return: Always 0
*/
int main(void)
{
    char *file_name = "example.txt";
    ssize_t chars_printed;

    chars_printed = read_file(file_name, 1024);

    if (chars_printed < 0)
    {
        fprintf(stderr, "Failed to read file: %s\n", file_name);
        return (EXIT_FAILURE);
    }

    return (EXIT_SUCCESS);
}
