#include "main.h"
#include <stdio.h>

/**
* main - Copies the contents of one file to another.
* @arg_count: The number of arguments supplied to the program.
* @arg_values: An array of pointers to the arguments.
*
* Return: 0 on success, or an exit code on failure.
*/
int main(int arg_count, char *arg_values[])
{
    int source_file_descriptor, destination_file_descriptor, bytes_read;
    char buffer[1024];
    
    if (arg_count != 3)
    {
        fprintf(stderr, "Usage: cp source_file destination_file\n");
        return (97);
    }
    
    source_file_descriptor = open(arg_values[1], O_RDONLY);
    if (source_file_descriptor == -1)
    {
        fprintf(stderr, "Error: Can't read from file %s\n", arg_values[1]);
        return (98);
    }
    
    destination_file_descriptor = open(arg_values[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
    if (destination_file_descriptor == -1)
    {
        fprintf(stderr, "Error: Can't write to %s\n", arg_values[2]);
        close(source_file_descriptor);
        return (99);
    }
    
    while ((bytes_read = read(source_file_descriptor, buffer, sizeof(buffer))) > 0)
    {
        if (write(destination_file_descriptor, buffer, bytes_read) != bytes_read)
        {
            fprintf(stderr, "Error: Can't write to %s\n", arg_values[2]);
            close(source_file_descriptor);
            close(destination_file_descriptor);
            return (99);
        }
    }
    
    if (bytes_read == -1)
    {
        fprintf(stderr, "Error: Can't read from file %s\n", arg_values[1]);
        close(source_file_descriptor);
        close(destination_file_descriptor);
        return (98);
    }
    
    close(source_file_descriptor);
    close(destination_file_descriptor);
    return (0);
}
