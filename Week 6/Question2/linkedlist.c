#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

LinkedList* createLinkedList()
{
    LinkedList* list;
    list = (LinkedList*)malloc(sizeof(LinkedList));
    (*list).head = NULL;
    (*list).count = 0;
    return list;
}

void insertStart(LinkedList* list, void* entry)
{
    LinkedListNode* node;
    node = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    node->data = entry;
    node->next = list->head;
    list->head = node;
    list->count += 1;
}

void* removeStart(LinkedList* list)
{
    LinkedListNode* temp;
    void* data; 
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
    newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
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

void printList(void* data)
{
    char* newData = (char*) data;
    printf("%s", newData); 
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

void freeNode(void* data)
{
    LinkedListNode* node = (LinkedListNode*)data;
    free(node->data);
    free(node);
}

void freeLinkedList(LinkedList* list, listFunc fp)
{
    LinkedListNode* currentNode = list->head;
    LinkedListNode* tempNode;
    while(currentNode->next != NULL)
    {
        tempNode = currentNode->next;
        fp(currentNode);
        currentNode = tempNode;
    }
    free(tempNode);
    free(list);
}