#include "../src/linked-list.h"

#include <stdio.h>

void printList(LinkedListPtr list);

int main()
{
    LinkedListPtr list = ll_createList(256);
    int quit = 0;
    while(!quit)
    {
        printList(list);
        printf("]: Insert after\n[: Insert before\n<: Go left\n>: Go right\nr: Remove node\nd: Delete Node\nc: Clear list\nf: Go to front\nb: Go to back\nq: quit\n");

        char input = getchar();
        char string[2] = "\0";

        switch(input)
        {
        case ']':
            printf("Insert after data: ");
            input = getchar();
            string[0] = input;
            ll_insertAfter(list, string);
            while(getchar() != '\n');
            break;
        case '[':
            printf("Insert before data: ");
            input = getchar();
            string[0] = input;
            ll_insertBefore(list, string);
            while(getchar() != '\n');
            break;
        case '=':
            printf("Replace data: ");
            input = getchar();
            string[0] = input;
            ll_replaceData(list, string);
            while(getchar() != '\n');
            break;
        case '<':
            getchar();
            ll_gotoPrev(list);
            break;
        case '>':
            getchar();
            ll_gotoNext(list);
            break;
        case 'r':
            getchar();
            ll_removeNode(list);
            break;
        case 'd':
            getchar();
            ll_deleteNode(list);
            break;
        case 'c':
            getchar();
            ll_clearList(list);
            break;
        case 'f':
            getchar();
            ll_gotoFront(list);
            break;
        case 'b':
            getchar();
            ll_gotoBack(list);
            break;
        case 'q':
            quit = 1;
            break;
        default:
            printf("Invalid input\n");
            break;
        }
        while(getchar() != '\n');
    }

    ll_deleteList(&list);
}

void printList(LinkedListPtr list)
{
    if(ll_getSize(list) < 1)
    {
        printf("[Empty List]\nq");
        return;
    }

    ll_printListDebug(list);

    int savedIdx = ll_getIndex(list);
    ll_gotoFront(list);

    printf("|");
    do
    {
        if(ll_getIndex(list) == savedIdx)
        {
            printf(" [%s] |", ll_getData(list));
        }
        else
        {
            printf(" %s |", ll_getData(list));
        }
    } while (ll_gotoNext(list));
    printf("\n");

    while(ll_getIndex(list) != savedIdx)
    {
        ll_gotoPrev(list);
    }
}