#include "linked-list.h"

#include <stdio.h>

int main()
{
    LinkedListPtr list1 = ll_createList(1);
    LinkedListPtr list2 = ll_createList(2);
    LinkedListPtr list3 = ll_createList(8);
    LinkedListPtr list4 = ll_createList(16);
    LinkedListPtr list5 = ll_createList(128);

    if(list1) printf("Failed buffer size > 1 requirment \n");

    printf("list2(buffer: 2) Index: %d Size: %d\n", ll_getIndex(list2), ll_getSize(list2));
    printf("list2(buffer: 8) Index: %d Size: %d\n", ll_getIndex(list3), ll_getSize(list3));
    printf("list2(buffer: 16) Index: %d Size: %d\n", ll_getIndex(list4), ll_getSize(list4));
    printf("list2(buffer: 128) Index: %d Size: %d\n", ll_getIndex(list5), ll_getSize(list5));

    printf("\nInsert after \"test\"\n");
    char* data1 = "test";
    ll_insertAfter(list2, data1);
    ll_insertAfter(list3, data1);
    ll_insertAfter(list4, data1);
    ll_insertAfter(list5, data1);
    printf("list2(buffer: 2) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list2), ll_getSize(list2), ll_getData(list2));
    printf("list2(buffer: 8) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list3), ll_getSize(list3), ll_getData(list3));
    printf("list2(buffer: 16) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list4), ll_getSize(list4), ll_getData(list4));
    printf("list2(buffer: 128) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list5), ll_getSize(list5), ll_getData(list5));

    printf("\nInsert after \"this data should overflow in most buffers\"\n");
    char* data2 = "this is data that should overflow most buffers";
    ll_insertAfter(list2, data2);
    ll_insertAfter(list3, data2);
    ll_insertAfter(list4, data2);
    ll_insertAfter(list5, data2);
    printf("list2(buffer: 2) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list2), ll_getSize(list2), ll_getData(list2));
    printf("list2(buffer: 8) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list3), ll_getSize(list3), ll_getData(list3));
    printf("list2(buffer: 16) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list4), ll_getSize(list4), ll_getData(list4));
    printf("list2(buffer: 128) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list5), ll_getSize(list5), ll_getData(list5));

    printf("\nInsert before \"another long data to overflow buffers\"\n");
    char* data3 = "another long data to overflow buffers";
    ll_insertBefore(list2, data3);
    ll_insertBefore(list3, data3);
    ll_insertBefore(list4, data3);
    ll_insertBefore(list5, data3);
    printf("list2(buffer: 2) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list2), ll_getSize(list2), ll_getData(list2));
    printf("list2(buffer: 8) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list3), ll_getSize(list3), ll_getData(list3));
    printf("list2(buffer: 16) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list4), ll_getSize(list4), ll_getData(list4));
    printf("list2(buffer: 128) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list5), ll_getSize(list5), ll_getData(list5));

    printf("\nGo to previous\n");
    ll_gotoPrev(list2);
    ll_gotoPrev(list3);
    ll_gotoPrev(list4);
    ll_gotoPrev(list5);
    printf("list2(buffer: 2) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list2), ll_getSize(list2), ll_getData(list2));
    printf("list2(buffer: 8) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list3), ll_getSize(list3), ll_getData(list3));
    printf("list2(buffer: 16) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list4), ll_getSize(list4), ll_getData(list4));
    printf("list2(buffer: 128) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list5), ll_getSize(list5), ll_getData(list5));

    printf("\nGo to next\n");
    ll_gotoNext(list2);
    ll_gotoNext(list3);
    ll_gotoNext(list4);
    ll_gotoNext(list5);
    printf("list2(buffer: 2) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list2), ll_getSize(list2), ll_getData(list2));
    printf("list2(buffer: 8) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list3), ll_getSize(list3), ll_getData(list3));
    printf("list2(buffer: 16) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list4), ll_getSize(list4), ll_getData(list4));
    printf("list2(buffer: 128) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list5), ll_getSize(list5), ll_getData(list5));

    printf("\nGo to front\n");
    ll_gotoFront(list2);
    ll_gotoFront(list3);
    ll_gotoFront(list4);
    ll_gotoFront(list5);
    printf("list2(buffer: 2) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list2), ll_getSize(list2), ll_getData(list2));
    printf("list2(buffer: 8) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list3), ll_getSize(list3), ll_getData(list3));
    printf("list2(buffer: 16) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list4), ll_getSize(list4), ll_getData(list4));
    printf("list2(buffer: 128) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list5), ll_getSize(list5), ll_getData(list5));

    printf("\nInsert before \"small data\"\n");
    char* data4 = "small data";
    ll_insertBefore(list2, data4);
    ll_insertBefore(list3, data4);
    ll_insertBefore(list4, data4);
    ll_insertBefore(list5, data4);
    printf("list2(buffer: 2) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list2), ll_getSize(list2), ll_getData(list2));
    printf("list2(buffer: 8) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list3), ll_getSize(list3), ll_getData(list3));
    printf("list2(buffer: 16) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list4), ll_getSize(list4), ll_getData(list4));
    printf("list2(buffer: 128) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list5), ll_getSize(list5), ll_getData(list5));

    printf("\nInsert after \"lorem ipsum something something\"\n");
    char* data5 = "lorem ipsum something something";
    ll_insertAfter(list2, data5);
    ll_insertAfter(list3, data5);
    ll_insertAfter(list4, data5);
    ll_insertAfter(list5, data5);
    printf("list2(buffer: 2) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list2), ll_getSize(list2), ll_getData(list2));
    printf("list2(buffer: 8) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list3), ll_getSize(list3), ll_getData(list3));
    printf("list2(buffer: 16) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list4), ll_getSize(list4), ll_getData(list4));
    printf("list2(buffer: 128) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list5), ll_getSize(list5), ll_getData(list5));

    printf("\nGo to back\n");
    ll_gotoBack(list2);
    ll_gotoBack(list3);
    ll_gotoBack(list4);
    ll_gotoBack(list5);
    printf("list2(buffer: 2) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list2), ll_getSize(list2), ll_getData(list2));
    printf("list2(buffer: 8) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list3), ll_getSize(list3), ll_getData(list3));
    printf("list2(buffer: 16) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list4), ll_getSize(list4), ll_getData(list4));
    printf("list2(buffer: 128) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list5), ll_getSize(list5), ll_getData(list5));

    printf("\nInsert before \"blah blah blah\"\n");
    char* data6 = "blah blah blah";
    ll_insertBefore(list2, data6);
    ll_insertBefore(list3, data6);
    ll_insertBefore(list4, data6);
    ll_insertBefore(list5, data6);
    printf("list2(buffer: 2) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list2), ll_getSize(list2), ll_getData(list2));
    printf("list2(buffer: 8) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list3), ll_getSize(list3), ll_getData(list3));
    printf("list2(buffer: 16) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list4), ll_getSize(list4), ll_getData(list4));
    printf("list2(buffer: 128) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list5), ll_getSize(list5), ll_getData(list5));

    printf("\nReplace data \"test123\"\n");
    char* data7 = "test123";
    ll_replaceData(list2, data7);
    ll_replaceData(list3, data7);
    ll_replaceData(list4, data7);
    ll_replaceData(list5, data7);
    printf("list2(buffer: 2) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list2), ll_getSize(list2), ll_getData(list2));
    printf("list2(buffer: 8) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list3), ll_getSize(list3), ll_getData(list3));
    printf("list2(buffer: 16) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list4), ll_getSize(list4), ll_getData(list4));
    printf("list2(buffer: 128) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list5), ll_getSize(list5), ll_getData(list5));


    printf("\nRemove node\n");
    ll_removeNode(list2);
    ll_removeNode(list3);
    ll_removeNode(list4);
    ll_removeNode(list5);
    printf("list2(buffer: 2) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list2), ll_getSize(list2), ll_getData(list2));
    printf("list2(buffer: 8) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list3), ll_getSize(list3), ll_getData(list3));
    printf("list2(buffer: 16) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list4), ll_getSize(list4), ll_getData(list4));
    printf("list2(buffer: 128) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list5), ll_getSize(list5), ll_getData(list5));

    printf("\nGo to back\n");
    ll_gotoBack(list2);
    ll_gotoBack(list3);
    ll_gotoBack(list4);
    ll_gotoBack(list5);
    printf("list2(buffer: 2) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list2), ll_getSize(list2), ll_getData(list2));
    printf("list2(buffer: 8) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list3), ll_getSize(list3), ll_getData(list3));
    printf("list2(buffer: 16) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list4), ll_getSize(list4), ll_getData(list4));
    printf("list2(buffer: 128) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list5), ll_getSize(list5), ll_getData(list5));

    printf("\nRemove node\n");
    ll_removeNode(list2);
    ll_removeNode(list3);
    ll_removeNode(list4);
    ll_removeNode(list5);
    printf("list2(buffer: 2) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list2), ll_getSize(list2), ll_getData(list2));
    printf("list2(buffer: 8) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list3), ll_getSize(list3), ll_getData(list3));
    printf("list2(buffer: 16) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list4), ll_getSize(list4), ll_getData(list4));
    printf("list2(buffer: 128) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list5), ll_getSize(list5), ll_getData(list5));

    printf("\nGo to front\n");
    ll_gotoFront(list2);
    ll_gotoFront(list3);
    ll_gotoFront(list4);
    ll_gotoFront(list5);
    printf("list2(buffer: 2) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list2), ll_getSize(list2), ll_getData(list2));
    printf("list2(buffer: 8) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list3), ll_getSize(list3), ll_getData(list3));
    printf("list2(buffer: 16) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list4), ll_getSize(list4), ll_getData(list4));
    printf("list2(buffer: 128) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list5), ll_getSize(list5), ll_getData(list5));

    printf("\nRemove node\n");
    ll_removeNode(list2);
    ll_removeNode(list3);
    ll_removeNode(list4);
    ll_removeNode(list5);
    printf("list2(buffer: 2) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list2), ll_getSize(list2), ll_getData(list2));
    printf("list2(buffer: 8) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list3), ll_getSize(list3), ll_getData(list3));
    printf("list2(buffer: 16) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list4), ll_getSize(list4), ll_getData(list4));
    printf("list2(buffer: 128) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list5), ll_getSize(list5), ll_getData(list5));

    printf("\nClear list\n");
    ll_clearList(list2);
    ll_clearList(list3);
    ll_clearList(list4);
    ll_clearList(list5);
    printf("list2(buffer: 2) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list2), ll_getSize(list2), ll_getData(list2));
    printf("list2(buffer: 8) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list3), ll_getSize(list3), ll_getData(list3));
    printf("list2(buffer: 16) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list4), ll_getSize(list4), ll_getData(list4));
    printf("list2(buffer: 128) Index: %d Size: %d Data: \"%s\"\n", ll_getIndex(list5), ll_getSize(list5), ll_getData(list5));

    ll_deleteList(&list2);
    ll_deleteList(&list3);
    ll_deleteList(&list4);
    ll_deleteList(&list5);

    if(list2 || list3 || list4 || list5)
    {
        printf("Failed list delete\n");
    }

}