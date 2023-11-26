#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct ListNode;

typedef struct ListNode* NodePtr;
typedef struct LinkedList* LinkedListPtr;

struct LinkedList
{
    NodePtr currentNode;
    int listIndex;
    int listSize;
    int dataBufferSize;
};

// Creates linked-list with given data buffer size
LinkedListPtr ll_createList(int bufferSize);

// Clears the list to continue being used
// Only deallocates nodes of list
void ll_clearList(LinkedListPtr list);

// Clears and deallocates linked-list entirely
void ll_deleteList(LinkedListPtr* list);

// Move current node once toward the back of the list
int ll_gotoNext(LinkedListPtr list);

// Move current node once toward the front of the list
int ll_gotoPrev(LinkedListPtr list);

// Move the current node to the back of the list
void ll_gotoBack(LinkedListPtr list);

// Move the current node to the front of the list
void ll_gotoFront(LinkedListPtr list);

// Inserts new node after current node
// Current node will point to new node after insertion
void ll_insertAfter(LinkedListPtr list, char* newData);

// Inserts new node before the current node
// Current node will point to new node after insertion
void ll_insertBefore(LinkedListPtr list, char* newData);

// Replace only the data in the current node
void ll_replaceData(LinkedListPtr list, char* newData);

// Removes the current node
// Shifts current node once toward the front of list
void ll_removeNode(LinkedListPtr list);

// Return data of current node
char* ll_getData(LinkedListPtr list);

#endif