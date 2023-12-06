#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct ListNode* ListNodePtr;
typedef struct LinkedList* LinkedListPtr;

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
// Shifts index toward the front of list
void ll_removeNode(LinkedListPtr list);

// Removes the current node
// Keeps index the same, and shifts toward front when deleting from back
void ll_deleteNode(LinkedListPtr list);

// Return data of current node
char* ll_getData(LinkedListPtr list);

// Return index of current node
int ll_getIndex(LinkedListPtr list);

// Return current size of list
int ll_getSize(LinkedListPtr list);

// Return data buffer size
int ll_getBufferSize(LinkedListPtr list);

void ll_printListDebug(LinkedListPtr list);

#endif