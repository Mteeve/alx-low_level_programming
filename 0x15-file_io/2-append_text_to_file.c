#include "main.h"
#include <string.h>

/**
* append_text - Appends text to the end of a file.
* @file_name: The name of the file to append to.
* @content: The text to append to the file.
*
* Return: 1 on success, -1 on failure.
*/
int append_text(const char *file_name, char *content)
{
    int file_descriptor, bytes_written;
    
    if (file_name == NULL)
        return (-1);
    
    file_descriptor = open(file_name, O_WRONLY | O_APPEND);
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
