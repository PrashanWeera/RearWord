#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "ReadFile.h"

FILE *file = NULL;

bool ReadFile_Init(char *fileName)
{
    if (file)
    {
        // Already opened ..
        perror("Error file already opened\n");
        return false;
    }

    // Open the file for reading
    file = fopen(fileName, "r");
    if (file == NULL)
    {
        perror("Error opening file\n");
        return false;
    }
    else
    {
        return true;
    }
}

bool ReadFile_Close()
{
    if (file)
    {
        // Close the file
        fclose(file);
        file = NULL;
        return true;
    }
    else
    {
        perror("Error No file to close..\n");
        return false;
    }
}

int ReadFile_GetNextLine(char *dataBuffer, int buff_size)
{
    int len = 0;
    if (file && buff_size > 0)
    {
        // Read each line from the file and print it
        if (fgets(dataBuffer, buff_size, file) != NULL)
        {
            // Remove new line ..
            len = strlen(dataBuffer);
            if (dataBuffer[len - 1] == '\n')
            {
                // Remove the newline character
                dataBuffer[len - 1] = '\0';
            }
            return 1;
        }
        else
        {
            perror("Error reading file ...\n");
            return 0;
        }
    }
    else
    {
        perror("Error no file or buffer size.\n");
        return 0;
    }
}