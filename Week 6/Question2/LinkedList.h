#ifndef LINKEDLIST_H
#define LINEDLIST_H

typedef struct LinkedListNode
{
    void* data;
    struct LinkedListNode* next;
} LinkedListNode;

typedef struct LinkedList
{
    LinkedListNode* head;
    int count;
} LinkedList;

typedef void (*listFunc) (void* data);

LinkedList* createLinkedList();

void insertStart(LinkedList* list, void* entry);

void* removeStart(LinkedList* list);

void insertLast(LinkedList* list, void* entry);

void* removeLast(LinkedList* list);

void printLinkedList(LinkedList* list, listFunc funcPtr);

void freeLinkedList(LinkedList* list, listFunc funcPtr);

#endif