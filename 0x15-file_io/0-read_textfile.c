#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * readAndPrintTextFile - Reads a text file and prints its content to STDOUT.
 * @filename: The name of the text file to be read.
 * @letters: The number of letters to be read from the file.
 *
 * Return: The actual number of bytes read and printed.
 *         0 if the function fails or if the filename is NULL.
 */
ssize_t readAndPrintTextFile(const char *filename, size_t letters)
{
    char *buffer;
    ssize_t file_descriptor;
    ssize_t bytes_read;
    ssize_t bytes_written;

    file_descriptor = open(filename, O_RDONLY);
    if (file_descriptor == -1)
        return (0);

    buffer = malloc(sizeof(char) * letters);
    bytes_read = read(file_descriptor, buffer, letters);
    bytes_written = write(STDOUT_FILENO, buffer, bytes_read);

    free(buffer);
    close(file_descriptor);

    return (bytes_written);
}
