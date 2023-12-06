#include "file_io.h"
#include "linked-list.h"

#include <stdio.h>

#define RETURN_SUCCESS 1
#define RETURN_FAILURE 0

// List headers and 1 line
#define MIN_LIST_SIZE 2

/*
SCHEMA:
-------------------------------------------------
account , ID , branch , name , operation , amount
-------------------------------------------------
*/

#define LINE_BUFFER_SIZE 256

// Function needs to return 0 for failure
typedef int (*conditionFunc)(char*, char*);

// Copies current file line to destination as null-terminated string
int file_lineToString(FILE* file, char* destination, int bufferSize)
{
    if(!file)
    {
        printf("Null file in lineToString\n");
        return RETURN_FAILURE;
    }

    if(!destination)
    {
        printf("Null destination in lineToString\n");
        return RETURN_FAILURE;
    }

    // Copy file line to buffer
    int nextChar = '\0';
    for(int lineIdx = 0; lineIdx < bufferSize - 1; ++lineIdx)
    {
        nextChar = fgetc(file);
        
        if(nextChar == '\n')
        {
            destination[lineIdx] = '\0';
            return RETURN_SUCCESS;
        }
        if(nextChar == EOF)
        {
            destination[lineIdx] = '\0';
            return EOF;
        }
        
        destination[lineIdx] = (char)nextChar;
    }

    // Null terminate buffer if buffer is too small
    destination[bufferSize] = '\0';

    // Exhauxt unfinished line if buffer is too small
    while(nextChar != '\n')
    {
        nextChar = fgetc(file);
        if(nextChar == EOF)
        {
            return EOF;
        }
    }

    printf("ERROR: Reached end of lineToString()\n");
    return RETURN_FAILURE;
}

// Clears list and imports csv file to list
// Each node contains a line, with column headers in the first node
int file_fileToList(char* filePath, LinkedListPtr rowList)
{
    if(!filePath)
    {
        printf("Null file path\n");
        return RETURN_FAILURE;
    }

    FILE* file = fopen(filePath, 'r');

    if(!file)
    {
        printf("Failed to open file\n");
        return RETURN_FAILURE;
    }

    // Create nodes for file lines
    ll_clearList(rowList);
    char nextLine = malloc(sizeof(char) * ll_getBufferSize(rowList));
    while(1)
    {
        if(file_lineToString(file, nextLine, ll_getBufferSize(rowList)) == EOF)
        {
            break;
        }

        ll_insertAfter(rowList, nextLine);
    }
    return RETURN_SUCCESS;
}

// Creates or clears file and moves data from list to file
int file_listToFile(char* filePath, LinkedListPtr rowList)
{
    if(ll_getSize < MIN_LIST_SIZE)
    {
        return RETURN_FAILURE;
    }

    if(!filePath)
    {
        printf("Null file path\n");
        return RETURN_FAILURE;
    }

    FILE* file = fopen(filePath, "w");

    if(!file)
    {
        printf("Failed to open file\n");
        return RETURN_FAILURE;
    }

    // Copy column headers without removing from list
    ll_gotoFront(rowList);
    fprintf(file, "%s\n", ll_getData(rowList));
    ll_gotoNext(rowList);

    // Move data from list to file
    do
    {
        fprintf(file, "%s\n", ll_getData(rowList));
        ll_deleteNode(rowList);
    } while (ll_getSize(rowList) >= MIN_LIST_SIZE);

    ll_gotoFront(rowList);
    fclose(file);
    return RETURN_SUCCESS;
}

// Appends list data to file
// Only column headers are retained in list
int file_appendListToFile(char* filePath, LinkedListPtr rowList)
{
    if(ll_getSize < MIN_LIST_SIZE)
    {
        return RETURN_FAILURE;
    }

    if(!filePath)
    {
        printf("Null file path\n");
        return RETURN_FAILURE;
    }

    FILE* file = fopen(filePath, "a");

    if(!file)
    {
        printf("Failed to open file\n");
        return RETURN_FAILURE;
    }

    // Move data from list to file
    ll_gotoFront(rowList);
    ll_gotoNext(rowList); // Skip column headers
    do
    {
        fprintf(file, "%s\n", ll_getData(rowList));
        ll_deleteNode(rowList);
    } while (ll_getSize(rowList) >= MIN_LIST_SIZE);

    ll_gotoFront(rowList);
    fclose(file);
    return RETURN_SUCCESS;
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