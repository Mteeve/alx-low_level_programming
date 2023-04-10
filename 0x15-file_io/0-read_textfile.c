#include <stdio.h>
#include <stdlib.h>
#include "main.h"


/**
* read_textfile- Read text file print to STDOUT.
* @filename: text file being read
* @letters: number of letters to be read
* Return: w- actual number of bytes read and printed
*        0 when function fails or filename is NULL.
*/

ssize_t read_textfile(const char *filename, size_t letters)
{
char *buf;
ssize_t fd;
ssize_t w;
ssize_t t;

fd = open(filename, O_RDONLY);
if (fd == -1)
return (0);
buf = malloc(sizeof(char) * letters);
t = read(fd, buf, letters);
w = write(STDOUT_FILENO, buf, t);

free(buf);
close(fd);
return (w);
}

/**
* main - Entry point
*
* Return: Always 0
*/
int main(void)
{
char *filename = "example.txt";
ssize_t chars_printed;

chars_printed = read_textfile(filename, 1024);
if (chars_printed < 0)
{
fprintf(stderr, "Failed to read file: %s\n", filename);
return (EXIT_FAILURE);
}

return (EXIT_SUCCESS);
}
