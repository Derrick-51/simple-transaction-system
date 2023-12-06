#include "linked-list.h"

#include <stdio.h>

struct Lists
{
    LinkedListPtr list1;
    LinkedListPtr list2;
    LinkedListPtr list3;
    LinkedListPtr list4;
};

void printListInfo(struct Lists lists);
void insertAfterTest(struct Lists lists, char* data);
void insertBeforeTest(struct Lists lists, char* data);
void replaceDataTest(struct Lists lists, char* data);
void gotoNextTest(struct Lists lists);
void gotoPrevTest(struct Lists lists);
void gotoFrontTest(struct Lists lists);
void gotoBackTest(struct Lists lists);
void removeNodeTest(struct Lists lists);
void deleteNodeTest(struct Lists lists);
void clearListTest(struct Lists lists);
void deleteListTest(struct Lists lists);


int main()
{
    LinkedListPtr list0 = ll_createList(1);

    struct Lists lists;
    lists.list1 = ll_createList(2);
    lists.list2 = ll_createList(8);
    lists.list3 = ll_createList(16);
    lists.list4 = ll_createList(256);

    if(list0) printf("Failed buffer size > 1 requirment \n\n");
    else printf("Passed buffer size > 1 requirment \n\n");

    printListInfo(lists);

    char* data1 = "test";
    insertAfterTest(lists, data1);

    printf("\n");
    ll_printListDebug(lists.list1);
    ll_printListDebug(lists.list2);
    ll_printListDebug(lists.list3);
    ll_printListDebug(lists.list4);
    
    char* data2 = "this is data that should overflow most buffers";
    insertAfterTest(lists, data2);

    printf("\n");
    ll_printListDebug(lists.list1);
    ll_printListDebug(lists.list2);
    ll_printListDebug(lists.list3);
    ll_printListDebug(lists.list4);

    removeNodeTest(lists);

    printf("\n");
    ll_printListDebug(lists.list1);
    ll_printListDebug(lists.list2);
    ll_printListDebug(lists.list3);
    ll_printListDebug(lists.list4);
    
    char* data3 = "another long data to overflow buffers";
    insertBeforeTest(lists, data3);
    
    gotoPrevTest(lists);
    
    gotoNextTest(lists);
    
    gotoFrontTest(lists);
    
    printf("\n[BOUNDS CHECK]\n");
    gotoPrevTest(lists);

    char* data4 = "small data";
    insertBeforeTest(lists, data4);
    
    char* data5 = "lorem ipsum something something";
    insertAfterTest(lists, data5);
    
    gotoBackTest(lists);
    
    printf("\n[BOUNDS CHECK]\n");
    gotoNextTest(lists);
    
    char* data6 = "blah blah blah";
    insertBeforeTest(lists, data6);
    
    char* data7 = "test123";
    replaceDataTest(lists, data7);
    
    removeNodeTest(lists);
    
    gotoBackTest(lists);
    
    char* data8 = "going going gone";
    insertAfterTest(lists, data8);

    char* data9 = "piece of cake";
    insertAfterTest(lists, data9);

    removeNodeTest(lists);
    
    gotoFrontTest(lists);
    
    removeNodeTest(lists);
    
    gotoNextTest(lists);
    
    deleteNodeTest(lists);
    
    gotoBackTest(lists);
    
    deleteNodeTest(lists);
    
    clearListTest(lists);
    
    deleteListTest(lists);
    
    
}




void printListInfo(struct Lists lists)
{
    printf("list2(buffer: 2) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(lists.list1), ll_getSize(lists.list1), ll_getData(lists.list1));
    printf("list2(buffer: 8) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(lists.list2), ll_getSize(lists.list2), ll_getData(lists.list2));
    printf("list2(buffer: 16) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(lists.list3), ll_getSize(lists.list3), ll_getData(lists.list3));
    printf("list2(buffer: 128) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(lists.list4), ll_getSize(lists.list4), ll_getData(lists.list4));
}

void insertAfterTest(struct Lists lists, char* data)
{
    printf("\nInsert after \"%s\"\n", data);
    ll_insertAfter(lists.list1, data);
    ll_insertAfter(lists.list2, data);
    ll_insertAfter(lists.list3, data);
    ll_insertAfter(lists.list4, data);
    printListInfo(lists);
    }

void insertBeforeTest(struct Lists lists, char* data)
{
    printf("\nInsert before \"%s\"\n", data);
    ll_insertBefore(lists.list1, data);
    ll_insertBefore(lists.list2, data);
    ll_insertBefore(lists.list3, data);
    ll_insertBefore(lists.list4, data);
    printListInfo(lists);
}

void replaceDataTest(struct Lists lists, char* data)
{
    printf("\nReplace data \"%s\"\n", data);
    ll_replaceData(lists.list1, data);
    ll_replaceData(lists.list2, data);
    ll_replaceData(lists.list3, data);
    ll_replaceData(lists.list4, data);
    printListInfo(lists);
}

void gotoNextTest(struct Lists lists)
{
    printf("\nGo to next\n");
    ll_gotoNext(lists.list1);
    ll_gotoNext(lists.list2);
    ll_gotoNext(lists.list3);
    ll_gotoNext(lists.list4);
    printListInfo(lists);
}

void gotoPrevTest(struct Lists lists)
{
    printf("\nGo to previous\n");
    ll_gotoPrev(lists.list1);
    ll_gotoPrev(lists.list2);
    ll_gotoPrev(lists.list3);
    ll_gotoPrev(lists.list4);
    printListInfo(lists);
}

void gotoFrontTest(struct Lists lists)
{
    printf("\nGo to front\n");
    ll_gotoFront(lists.list1);
    ll_gotoFront(lists.list2);
    ll_gotoFront(lists.list3);
    ll_gotoFront(lists.list4);
    printListInfo(lists);
}

void gotoBackTest(struct Lists lists)
{
    printf("\nGo to back\n");
    ll_gotoBack(lists.list1);
    ll_gotoBack(lists.list2);
    ll_gotoBack(lists.list3);
    ll_gotoBack(lists.list4);
    printListInfo(lists);
}

void removeNodeTest(struct Lists lists)
{
    printf("\nRemove node\n");
    ll_removeNode(lists.list1);
    ll_removeNode(lists.list2);
    ll_removeNode(lists.list3);
    ll_removeNode(lists.list4);
    printListInfo(lists);
}

void deleteNodeTest(struct Lists lists)
{
    printf("\nDelete node\n");
    ll_deleteNode(lists.list1);
    ll_deleteNode(lists.list2);
    ll_deleteNode(lists.list3);
    ll_deleteNode(lists.list4);
    printListInfo(lists);
}

void clearListTest(struct Lists lists)
{
    printf("\nClear list\n");
    ll_clearList(lists.list1);
    ll_clearList(lists.list2);
    ll_clearList(lists.list3);
    ll_clearList(lists.list4);
    printListInfo(lists);
}

void deleteListTest(struct Lists lists)
{
    printf("\nDelete list\n");
    ll_deleteList(&(lists.list1));
    ll_deleteList(&(lists.list2));
    ll_deleteList(&(lists.list3));
    ll_deleteList(&(lists.list4));
    
    if(lists.list1 || lists.list2 || lists.list3 || lists.list4)
    {
        printf("Failed list delete\n");
    }
    else
    {
        printf("Passed list delete\n");
    }
}