#include "linked-list.h"

#include <stdio.h>
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
    ListNodePtr front;
    ListNodePtr back;
    int listIndex;
    int listSize;
    int dataBufferSize;
};

char* list_getData(ListNodePtr node)
{
    if(!node->data)
    {
        printf("[Node data empty]");
    }

    return node->data;
}

// Allocates and sets list node data
struct ListNode* list_setData(ListNodePtr node, char* newData, int bufferSize)
{
    while(!node->data)
    {
        node->data = malloc(sizeof(char) * bufferSize);
    }

    //strncpy(node->data, newData, bufferSize - 1);
    //(node->data)[bufferSize - 1] = '\0';
    snprintf(node->data, bufferSize, "%s", newData);

    return node;
}

// Insert new node after current node
// Returns new node
struct ListNode* list_insertAfter(ListNodePtr node, char* newData, int bufferSize)
{
    struct ListNode* newNode = malloc(sizeof(struct ListNode));
    newNode->prev = NULL;
    newNode->next = NULL;
    // Without initializing data, new node may be allocated with old node address 
    // leading to errors when inserting after deletion
    newNode->data = NULL;
    newNode = list_setData(newNode, newData, bufferSize);

    // Empty list
    if(!node)
    {
        return newNode;
    }

    // Insert at back of list
    if(!(node->next))
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

    return newNode;
}

// Insert new node before current node
// Returns new node
struct ListNode* list_insertBefore(ListNodePtr node, char* newData, int bufferSize)
{
    struct ListNode* newNode = malloc(sizeof(struct ListNode));
    newNode->prev = NULL;
    newNode->next = NULL;
    // Without this, new node may be allocated with old address data
    // leading to errors when inserting after deletion
    newNode->data = NULL;
    newNode = list_setData(newNode, newData, bufferSize);

    // Empty list
    if(!node)
    {
        return newNode;
    }

    // Insert at front of list
    if(!(node->prev))
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

    return newNode;
}

// Returns the next node of the list
struct ListNode* list_gotoNext(ListNodePtr node)
{
    // Empty list
    if(!node)
    {
        return NULL;
    }

    return node->next;
}

// Returns the previous node of the list
struct ListNode* list_gotoPrev(ListNodePtr node)
{
    // Empty list
    if(!node)
    {
        return NULL;
    }

    return node->prev;
}

// Not needed with front and back pointers
/*
// Returns the back node of the list
struct ListNode* list_gotoBack(ListNodePtr node)
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
struct ListNode* list_gotoFront(ListNodePtr node)
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
*/

// ListIndexShift is the value that is used to shift the list index
// Index shifts left after removal
struct ListNode* list_removeNode(ListNodePtr node, int* listIndexShift)
{
    if(!node)
    {
        printf("Cannot remove node in empty list\n");
        return NULL;
    }

    struct ListNode* prevNode = node->prev;
    struct ListNode* nextNode = node->next;

    if(node->data)
    {
        free(node->data);
    }

    free(node);

    // Middle of list
    if(prevNode && nextNode)
    {
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        *listIndexShift = -1;
        return prevNode;
    }

    // Back of list
    if(prevNode)
    {
        prevNode->next = NULL;
        *listIndexShift = -1;
        return prevNode;
    }

    // Front of list
    if(nextNode)
    {
        nextNode->prev = NULL;
        *listIndexShift = 0;
        return nextNode;
    }

    // List is now empty
    return NULL;
}

// ListIndexShift is the value that is used to shift the list index
// Index remains the same after deletion unless at end of list
struct ListNode* list_deleteNode(ListNodePtr node, int* listIndexShift)
{
    if(!node)
    {
        printf("Cannot remove node in empty list\n");
        return NULL;
    }

    struct ListNode* prevNode = node->prev;
    struct ListNode* nextNode = node->next;

    if(node->data)
    {
        free(node->data);
    }

    free(node);

    // Middle of list
    if(prevNode && nextNode)
    {
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        *listIndexShift = 0;
        return nextNode;
    }

    // Back of list
    if(prevNode)
    {
        prevNode->next = NULL;
        *listIndexShift = -1;
        return prevNode;
    }

    // Front of list
    if(nextNode)
    {
        nextNode->prev = NULL;
        *listIndexShift = 0;
        return nextNode;
    }

    // List is now empty
    return NULL;
}

struct ListNode* list_clearList(ListNodePtr node)
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
    list->front = NULL;
    list->back = NULL;
    list->listIndex = -1;
    list->listSize = 0;
    list->dataBufferSize = dataBufferSize;

    return list;
}

// Clears the list to continue being used
// Only deallocates nodes of list
void ll_clearList(LinkedListPtr list)
{
    list->currentNode = list_clearList(list->currentNode);
    list->listIndex = -1;
    list->listSize = 0;
}

// Clears and deallocates linked-list entirely
void ll_deleteList(LinkedListPtr* list)
{
    if((*list)->currentNode)
    {
        list_clearList((*list)->currentNode);
    }

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

    list->currentNode = list->back;
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

    list->currentNode = list->front;
    list->listIndex = 0;
}

// Inserts new node after current node
// Current node will point to new node after insertion
void ll_insertAfter(LinkedListPtr list, char* newData)
{
    if(!newData)
    {
        printf("Cannot insert null data string\n");
        return;
    }

    list->currentNode = list_insertAfter(list->currentNode, newData, list->dataBufferSize);
    list->listIndex += 1;
    list->listSize += 1;

    // Update front and back pointers
    if(list->listSize == 1)
    {
        list->front = list->currentNode;
    }

    if(list->listIndex == (list->listSize - 1))
    {
        list->back = list->currentNode;
    }
}

// Inserts new node before the current node
// Current node will point to new node after insertion
void ll_insertBefore(LinkedListPtr list, char* newData)
{
    if(!newData)
    {
        printf("Cannot insert null data string\n");
        return;
    }

    if(!list->currentNode)
    {
        list->currentNode = list_insertBefore(list->currentNode, newData, list->dataBufferSize);
        list->listIndex = 0;
        list->listSize = 1;
        return;
    }

    list->currentNode = list_insertBefore(list->currentNode, newData, list->dataBufferSize);
    list->listSize += 1;

    // Update front and back pointers
    if(list->listSize == 1)
    {
        list->back = list->currentNode;
    }

    if(list->listIndex == 0)
    {
        list->front = list->currentNode;
    }
}

// Replace only the data in the current node
void ll_replaceData(LinkedListPtr list, char* newData)
{
    if(!newData)
    {
        printf("Cannot replace with null data string\n");
        return;
    }

    if(!list->currentNode)
    {
        printf("Cannot replace data in empty list\n");
        return;
    }

    list_setData(list->currentNode, newData, list->dataBufferSize);
}

// Removes the current node
// Shifts index once toward the front of list
void ll_removeNode(LinkedListPtr list)
{
    int listIndexShift = 0;
    list->currentNode = list_removeNode(list->currentNode, &listIndexShift);

    // Empty list
    if(!list->currentNode)
    {
        list->front = NULL;
        list->back = NULL;
        list->listIndex = -1;
        list->listSize = 0;
        return;
    }

    // Current index shifts toward front of list
    list->listIndex += listIndexShift;
    list->listSize -= 1;

    // Update front and back pointers
    if(list->listIndex == 0)
    {
        list->front = list->currentNode;
    }

    if(list->listIndex == list->listSize - 1)
    {
        list->back = list->currentNode;
    }
}

// Removes the current node
// Keeps index the same, and shifts toward front when deleting from back
void ll_deleteNode(LinkedListPtr list)
{
    int listIndexShift = 0;
    list->currentNode = list_deleteNode(list->currentNode, &listIndexShift);

    // Empty list
    if(!list->currentNode)
    {
        list->front = NULL;
        list->back = NULL;
        list->listIndex = -1;
        list->listSize = 0;
        return;
    }

    // Current index shifts toward front only when deleting from back
    list->listIndex += listIndexShift;
    list->listSize -= 1;

    // Update front and back pointers
    if(list->listIndex == 0)
    {
        list->front = list->currentNode;
    }

    if(list->listIndex == list->listSize - 1)
    {
        list->back = list->currentNode;
    }
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

// Return data buffer size
int ll_getBufferSize(LinkedListPtr list)
{
    return list->dataBufferSize;
}

void ll_printListDebug(LinkedListPtr list)
{
    printf("Previous Node: %p\nCurrent Node: %p\nNext Node: %p\n\n", list->currentNode->prev, list->currentNode, list->currentNode->next);
}