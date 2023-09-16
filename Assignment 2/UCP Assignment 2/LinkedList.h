#ifndef LINKEDLIST_H
#define LINEDLIST_H

#define FALSE 0
#define TRUE !FALSE

typedef struct Snake
{
    int ROW;
    int COL;
    char symbol;
} Snake;

typedef struct LinkedListNode
{
    void* data;
    struct LinkedListNode* next;
    struct LinkedListNode* prev;
} LinkedListNode;

typedef struct LinkedList
{
    LinkedListNode* head;
    int count;
} LinkedList;

typedef void (*listFunc) (void* data);

LinkedList* createLinkedList();

LinkedListNode* createNode();

void insertStart(LinkedList* list, void* entry);

void* removeStart(LinkedList* list);

void insertLast(LinkedList* list, void* entry);

void* removeLast(LinkedList* list);

void* getData(LinkedListNode* node);

void setData(LinkedListNode* node, void* entry);

void printLinkedList(LinkedList* list, listFunc funcPtr);

void freeLinkedList(LinkedList* list);

void readFile(char*, int* , int*, LinkedList*);

void move(int ROWS, int COLS, char input, LinkedList* snake, char** errorMessage, int grow);

void printMap(int** array, int ROWS, int COLS, LinkedList* snake, int foodx, int foody, int score, int goal);

int checkWin(int foodX, int foodY, LinkedList* snake);

#endif