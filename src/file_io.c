#include "file_io.h"
#include "linked-list.h"

#include <stdio.h>

/*
SCHEMA:
-------------------------------------------------
account , ID , branch , name , operation , amount
-------------------------------------------------
*/

#define LINE_BUFFER_SIZE 256


int file_lineToString(FILE* file, char* destination)
{
    int nextChar = '\0';
    for(int lineIdx = 0; lineIdx < LINE_BUFFER_SIZE - 1; ++lineIdx)
    {
        nextChar = fgetc(file);

        if(nextChar == '\n')
        {
            destination[lineIdx] = '\0';
            return 0;
        }
        if(nextChar == EOF)
        {
            return EOF;
        }
        
        destination[lineIdx] = (char)nextChar;
    }
}

LinkedListPtr file_fileToList(char* filePath)
{
    if(!filePath)
    {
        printf("Null file path\n");
    }

    FILE* file = fopen(filePath, 'r');

    if(!file)
    {
        printf("Failed to open file\n");
    }

    LinkedListPtr list = ll_createList(LINE_BUFFER_SIZE);
    char nextLine[LINE_BUFFER_SIZE];
    
    while(1)
    {
        if(file_lineToString(file, nextLine) == EOF)
        {
            break;
        }

        ll_insertAfter(list, nextLine);
    }
}

char* file_filterLines(LinkedListPtr rowList, char* columnName, char* target)
{

}

char* file_findAccountLines(LinkedListPtr list, char* searchTarget)
{

}

char* file_findBranchLines(LinkedListPtr list, char* searchTarget)
{

}

char* file_findNameLines(LinkedListPtr list, char* searchTarget)
{

}

char* file_findOperationLines(LinkedListPtr list, char* searchTarget)
{

}
