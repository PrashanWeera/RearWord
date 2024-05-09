#include <stdio.h>
#include <stdbool.h>

#include "ReadFile.h"



int main(int argc, char* argv[]) 
{
    int BUFF_SIZE = 20;
    char DatBuff[BUFF_SIZE];
    // Check if there are command-line arguments
    if (argc < 2) 
    {
        printf("Usage: %s [path for the word list] ...\n", argv[0]);
        return 1; // Return an error code
    }

    // Print the arguments passed to the program
    printf("Arguments passed:\n");
    for (int i = 1; i < argc; i++) 
    {
        printf("Argument %d: %s\n", i, argv[i]);
    }

    if(ReadFile_Init(argv[1]))
    {
        for (size_t i = 0; i < 20; i++)
        {
            if(ReadFile_GetNextLine(DatBuff,BUFF_SIZE))
            {
                printf("Line => %s\n", DatBuff);
            }
            else
            {
                printf("Error Reading\n");
            }
        }
        
    }
    else
    {
        printf("Error reading file ...\n");
    }

    ReadFile_Close();


    return 0;
}