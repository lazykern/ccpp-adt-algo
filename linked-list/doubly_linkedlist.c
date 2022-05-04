#include <stdio.h>
#include <stdlib.h>

typedef struct DoublyNode
{
    int data;
    DoublyNode *next;
    DoublyNode *prev;
} DoublyNode;

typedef struct DoublyLinkedList
{
    DoublyNode *head;
    DoublyNode *tail;
    int size;
} DoublyLinkedList;

