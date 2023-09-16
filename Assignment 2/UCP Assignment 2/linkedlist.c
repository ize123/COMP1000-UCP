#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

LinkedList* createLinkedList()
{
    LinkedList* list = NULL;
    list = (LinkedList*)malloc(sizeof(LinkedList));
    (*list).head = NULL;
    (*list).count = 0;
    return list;
}

void insertStart(LinkedList* list, void* entry)
{
    LinkedListNode* node = createNode();
    node->data = entry;
    node->next = list->head;
    node->prev = NULL;
    list->head = node;
    list->count += 1;
}

LinkedListNode* createNode()
{
    LinkedListNode* node = NULL;
    node = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    node->data = NULL;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void* removeStart(LinkedList* list)
{
    LinkedListNode* temp;
    void* data; 
    temp = NULL;
    temp = list->head;
    list->head = list->head->next;
    list->count -= 1;
    data = temp->data;
    /*free(temp->data);*/
    free(temp);
    return data;
}

void insertLast(LinkedList* list, void* entry)
{
    LinkedListNode* lastNode;
    LinkedListNode* newNode;
    /* Create new node */
    newNode = createNode();
    newNode->data = entry;
    lastNode = list->head;
    while (lastNode->next != NULL)
    {
        lastNode = lastNode->next;
    }

    lastNode->next = newNode;
    list->count += 1;
}

void* removeLast(LinkedList* list)
{   
    void* data;
    if(list->head != NULL)
    {
        if(list->head->next == NULL)
        {
            /*free(list->head->data);*/
            free(list->head);
            list->head = NULL;
        }
        else
        {
            LinkedListNode* secondLast = list->head;
            LinkedListNode* lastNode;
            while(secondLast->next->next != NULL)
            {
                secondLast = secondLast->next;
            }

            lastNode = secondLast->next;
            data = lastNode->data;
            /*free(lastNode->data);
            free(lastNode);*/
            secondLast->next = NULL;   
            free(lastNode);        
        }
    }
    list->count -= 1;
    return data;
}

void* getData(LinkedListNode* node)
{
    void* data = node->data;
    return data;
}

void setData(LinkedListNode* node, void* entry)
{
    node->data = NULL;
    free(node->data);
    node->data = entry;
}

void printLinkedList(LinkedList* list, listFunc fp)
{
    LinkedListNode* node = list->head; 
    while(node->next != NULL)
    {
        fp(node->data);
        node = node->next;
    }
}

void freeLinkedList(LinkedList* list)
{
    LinkedListNode* node;
    LinkedListNode* nextNode;
    node = list->head;
    while(node != NULL)
    {
        nextNode = node->next;
        free(node->data);
        free(node);
        node = nextNode;
    }
    free(list);
}