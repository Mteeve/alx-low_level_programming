#include "main.h"
#include <stdio.h>

/**
* main - Copies the contents of one file to another.
* @argc: The number of arguments supplied to the program.
* @argv: An array of pointers to the arguments.
*
* Return: 0 on success, or an exit code on failure.
*/

int main(int argc, char *argv[])
{
int fd_from, fd_to, n;
char buffer[1024];

if (argc != 3)
{
fprintf(stderr, "Usage: cp file_from file_to\n");
return (97);
}

fd_from = open(argv[1], O_RDONLY);
if (fd_from == -1)
{
fprintf(stderr, "Error: Can't read from file %s\n", argv[1]);
return (98);
}

fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
if (fd_to == -1)
{
fprintf(stderr, "Error: Can't write to %s\n", argv[2]);
close(fd_from);
return (99);
}

while ((n = read(fd_from, buffer, sizeof(buffer))) > 0)
{
if (write(fd_to, buffer, n) != n)
{
fprintf(stderr, "Error: Can't write to %s\n", argv[2]);
close(fd_from);
close(fd_to);
return (99);
}
}

if (n == -1)
{
fprintf(stderr, "Error: Can't read from file %s\n", argv[1]);
close(fd_from);
close(fd_to);
return (98);
}

close(fd_from);
close(fd_to);
return (0);
}
