#include "linked-list.h"

#include <string.h>
#include <stdlib.h>

#define RETURN_SUCCESS 1
#define RETURN_FAILURE 0

struct ListNode
{
    struct ListNode* next;
    struct ListNode* prev;
    char* data;
};

struct LinkedList
{
    ListNodePtr currentNode;
    int listIndex;
    int listSize;
    int dataBufferSize;
};

struct ListNode* list_createList()
{
    struct ListNode* list = malloc(sizeof(struct ListNode));
    list->next = NULL;
    list->prev = NULL;
    list->data = NULL;

    return list;
}

char* list_getData(struct ListNode* node)
{
    if(!node->data)
    {
        printf("[Node data empty]");
    }

    return node->data;
}

// Allocates and sets list node data
struct ListNode* list_setData(struct ListNode* node, char* newData, int bufferSize)
{
    if(node->data)
    {
        free(node->data);
        node->data = NULL;
    }

    node->data = malloc(sizeof(char) * bufferSize);
    strncpy(node->data, newData, bufferSize - 1);
    node->data[bufferSize - 1] = '\0';

    return node;
}

// Insert new node after current node
// Returns new node
struct ListNode* list_insertAfter(struct ListNode* node, char* newData, int bufferSize)
{
    struct ListNode* newNode = malloc(sizeof(struct ListNode));

    // Empty list
    if(!node)
    {
        return newNode;
    }

    // Insert at back of list
    if(!node->next)
    {
        node->next = newNode;
        newNode->prev = node;
        return newNode;
    }

    struct ListNode* pushedNode = node->next;
    node->next = newNode;
    newNode->prev = node;
    newNode->next = pushedNode;
    pushedNode->prev = newNode;

    newNode = list_setData(newNode, newData, bufferSize);

    return newNode;
}

// Insert new node before current node
// Returns new node
struct ListNode* list_insertBefore(struct ListNode* node, char* newData, int bufferSize)
{
    struct ListNode* newNode = malloc(sizeof(struct ListNode));

    // Empty list
    if(!node)
    {
        return newNode;
    }

    // Insert at front of list
    if(!node->prev)
    {
        node->prev = newNode;
        newNode->next = node;
        return newNode;
    }

    struct ListNode* pushedNode = node->prev;
    node->prev = newNode;
    newNode->next = node;
    newNode->prev = pushedNode;
    pushedNode->next = newNode;

    newNode = list_setData(newNode, newData, bufferSize);

    return newNode;
}

// Returns the next node of the list
struct ListNode* list_gotoNext(struct ListNode* node)
{
    // Empty list
    if(!node)
    {
        return NULL;
    }

    return node->next;
}

// Returns the previous node of the list
struct ListNode* list_gotoPrev(struct ListNode* node)
{
    // Empty list
    if(!node)
    {
        return NULL;
    }

    return node->prev;
}

// Returns the back node of the list
struct ListNode* list_gotoBack(struct ListNode* node)
{
    // Empty list
    if(!node)
    {
        return NULL;
    }

    while(node->next)
    {
        node = node->next;
    }

    return node;
}

// Returns the front node of the list
struct ListNode* list_gotoFront(struct ListNode* node)
{
    // Empty list
    if(!node)
    {
        return NULL;
    }

    while(node->prev)
    {
        node = node->prev;
    }

    return node;
}

// ListIndexShift is the value that is used to shift the list index
struct ListNode* list_removeNode(struct ListNode* node, int* listIndexShift)
{
    struct ListNode* prevNode = node->prev;
    struct ListNode* nextNode = node->next;

    free(node);

    if(prevNode && nextNode)
    {
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        *listIndexShift = -1;
        return prevNode;
    }

    if(prevNode)
    {
        prevNode->next = NULL;
        *listIndexShift = -1;
        return prevNode;
    }

    if(nextNode)
    {
        nextNode->prev = NULL;
        *listIndexShift = 0;
        return nextNode;
    }

    // List is now empty
    return NULL;
}

struct ListNode* list_clearList(struct ListNode* node)
{
    node = list_gotoBack(node);

    int unused = 0; // Needed for function interface
    while(node = list_removeNode(node, &unused));

    return NULL;
}

// Creates linked-list with given data buffer size
LinkedListPtr ll_createList(int dataBufferSize)
{
    if(dataBufferSize < 2)
    {
        printf("List cannot have a buffer size less than 2\n");
        return NULL;
    }

    LinkedListPtr list = malloc(sizeof(struct LinkedList));
    list->currentNode = NULL;
    list->listIndex = -1;
    list->listSize = 0;
    list->dataBufferSize = dataBufferSize;

    return list;
}

// Clears the list to continue being used
// Only deallocates nodes of list
void ll_clearList(LinkedListPtr list)
{
    list_clearList(list->currentNode);
    list->listIndex = -1;
    list->listSize = 0;
}

// Clears and deallocates linked-list entirely
void ll_deleteList(LinkedListPtr* list)
{
    if(!(*list)->currentNode)
    {
        printf("Cannot delete empty list\n");
        return RETURN_FAILURE;
    }

    list_clearList((*list)->currentNode);
    free(*list);
    *list = NULL;
}

// Move current node once toward the back of the list
int ll_gotoNext(LinkedListPtr list)
{
    if(!list->currentNode)
    {
        printf("Cannot traverse empty list\n");
        return RETURN_FAILURE;
    }

    if(!list->currentNode->next)
    {
        printf("Currently at end of list\n");
        return RETURN_FAILURE;
    }

    list->currentNode = list_gotoNext(list->currentNode);
    list->listIndex += 1;

    return RETURN_SUCCESS;
}

// Move current node once toward the front of the list
int ll_gotoPrev(LinkedListPtr list)
{
    if(!list->currentNode)
    {
        printf("Cannot traverse empty list\n");
        return RETURN_FAILURE;
    }

    if(!list->currentNode->prev)
    {
        printf("Currently at front of list\n");
        return RETURN_FAILURE;
    }

    list->currentNode = list_gotoPrev(list->currentNode);
    list->listIndex -= 1;

    return RETURN_SUCCESS;
}

// Move the current node to the back of the list
void ll_gotoBack(LinkedListPtr list)
{
    if(!list->currentNode)
    {
        printf("Cannot traverse empty list\n");
        return;
    }

    list->currentNode = list_gotoBack(list->currentNode);
    list->listIndex = list->listSize - 1;
}

// Move the current node to the front of the list
void ll_gotoFront(LinkedListPtr list)
{
    if(!list->currentNode)
    {
        printf("Cannot traverse empty list\n");
        return;
    }

    list->currentNode = list_gotoFront(list->currentNode);
    list->listIndex = 0;
}

// Inserts new node after current node
// Current node will point to new node after insertion
void ll_insertAfter(LinkedListPtr list, char* newData)
{
    list->currentNode = list_insertAfter(list->currentNode, newData, list->dataBufferSize);
    list->listIndex += 1;
    list->listSize += 1;
}

// Inserts new node before the current node
// Current node will point to new node after insertion
void ll_insertBefore(LinkedListPtr list, char* newData)
{
    if(!list->currentNode)
    {
        list->currentNode = list_insertBefore(list->currentNode, newData, list->dataBufferSize);
        list->listIndex = 0;
        list->listSize = 1;
        return;
    }

    list->currentNode = list_insertBefore(list->currentNode, newData, list->dataBufferSize);
    list->listSize += 1;
}

// Replace only the data in the current node
void ll_replaceData(LinkedListPtr list, char* newData)
{
    if(!list->currentNode)
    {
        printf("Cannot replace data in empty list\n");
        return;
    }

    list_setData(list->currentNode, newData, list->dataBufferSize);
}

// Removes the current node
// Shifts current node once toward the front of list
void ll_removeNode(LinkedListPtr list)
{
    int listIndexShift = 0;
    list->currentNode = list_removeNode(list->currentNode, &listIndexShift);

    // Empty list
    if(!list->currentNode)
    {
        list->listIndex = -1;
        list->listSize = 0;
        return;
    }

    // Current index either shifts left or remains the same after removal
    list->listIndex += listIndexShift;
    list->listSize -= 1;
}

// Return data of current node
char* ll_getData(LinkedListPtr list)
{
    if(!list->currentNode)
    {
        printf("Cannot get data from empty list\n");
        return NULL;
    }

    return list_getData(list->currentNode);
}

// Return index of current node
int ll_getIndex(LinkedListPtr list)
{
    return list->listIndex;
}

// Return current size of list
int ll_getSize(LinkedListPtr list)
{
    return list->listSize;
}