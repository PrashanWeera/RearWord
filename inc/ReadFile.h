#ifndef READ_FILE_H
#define READ_FILE_H

bool ReadFile_Init(char * fileName);
bool ReadFile_Close();
int ReadFile_GetNextLine(char* dataBuffer, int buff_size);


#endif // READ_FILE_H