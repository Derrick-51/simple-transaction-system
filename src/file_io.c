#include "file_io.h"
#include "linked-list.h"

#include <stdio.h>

#define RETURN_SUCCESS 1
#define RETURN_FAILURE 0

/*
SCHEMA:
-------------------------------------------------
account , ID , branch , name , operation , amount
-------------------------------------------------
*/

#define LINE_BUFFER_SIZE 256

// Function needs to return 0 for failure
typedef int (*conditionFunc)(char*, char*);


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

int file_filterColumnCondition(
    LinkedListPtr rowList, 
    char* columnName, 
    char* target, 
    conditionFunc conditionFunc)
{
    if(ll_getSize(rowList) < 2)
    {
        printf("Cannot filter empty list\n");
        return RETURN_FAILURE;
    }

    // Skip header row
    ll_gotoFront(rowList);
    ll_gotoNext(rowList);

    while(ll_getIndex(rowList) < ll_getSize(rowList))
    {
        char* currentLine = ll_getData(rowList);

        if(conditionFunc(columnName, target))
        {
            ll_gotoNext(rowList);
        }
        else
        {
            ll_deleteNode(rowList);
        }
    }

    ll_gotoFront(rowList);
    return RETURN_SUCCESS;
}