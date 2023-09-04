#include <string.h>
#include "main.h"

/**
* create_new_file - Creates a new file and writes text to it.
* @file_name: The name of the file to create.
* @content: The text to write to the file.
*
* Return: 1 on success, -1 on failure.
*/
int create_new_file(const char *file_name, char *content)
{
    int file_descriptor, bytes_written;
    
    if (file_name == NULL)
        return (-1);
    
    file_descriptor = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0600);
    if (file_descriptor == -1)
        return (-1);
    
    if (content != NULL)
    {
        bytes_written = write(file_descriptor, content, strlen(content));
        if (bytes_written == -1)
        {
            close(file_descriptor);
            return (-1);
        }
    }
    
    close(file_descriptor);
    return (1);
}
