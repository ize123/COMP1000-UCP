#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void printMap(int** array, int ROWS, int COLS, LinkedList* snake, int foodX, int foodY, int score, int goal)
{
    int i, j;
    LinkedListNode* node = snake->head;

    /*Draw border of the map*/
    for(i = 0; i < ROWS; i++) /* This is to draw the border of the game  */
    {
        for(j = 0; j < COLS; j++)
        {
            if(i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1)
            {
                array[i][j] = '*';
            }
            else
            {
                array[i][j] = ' ';
            }
        }
    }
    
    /*Draw food*/
    array[foodX][foodY] = '@';

    /*Draw Snake*/
    while(node != NULL)
    {
        Snake s1 = *(Snake*)getData(node);
        array[s1.ROW + 1][s1.COL + 1] = s1.symbol;
        node = node->next;
    }

    /* Print out all the symbols that are stored on the array */
    for(i = 0; i < ROWS; i++) 
    {
        for(j = 0; j < COLS; j++)
        {   
            printf("%c", array[i][j]);
        }
        printf("\n");
    }

    /*Print the score*/
    printf("Current score: %d/%d\n", score, goal);
}

/*Checks to see if the head of the snake is on the same position as the food*/
int checkWin(int foodX, int foodY, LinkedList* snake)
{
    int WIN = FALSE;
    LinkedListNode* node = snake->head;
    Snake* head = (Snake*)getData(node);
    if(head->ROW + 1 == foodX && head->COL + 1 == foodY)
    {
        WIN = TRUE;
    }
    return WIN;
}

/*Used for the main movement of the snake*/
void move(int ROWS, int COLS, char input, LinkedList* snake, char** errorMessage, int grow)
{
    LinkedListNode* snakeHead = snake->head;
    LinkedListNode* nextBodyPart = snakeHead->next;

    Snake head = *(Snake*)getData(snakeHead);
    Snake body = *(Snake*)getData(nextBodyPart);
    *errorMessage =  "";
    switch(input)
    {
        case 'w':
        if(head.ROW == body.ROW + 1) /* Check to see if the body of the snake is behind the head and if so prevent the move from happening */
        {
            *errorMessage = "You cannot go backwards\n";
        }
        else if(head.ROW > 0) /* Main movement */
        {
            LinkedListNode* curr = snake->head;
            Snake temp;
            Snake new;
            if(grow == TRUE) /*If the snake has eaten food then grow*/
            {
                Snake* newPart = (Snake*)malloc(sizeof(Snake));
                newPart->COL = head.COL;
                newPart->ROW = head.ROW - 1;
                newPart->symbol = '^';
                insertLast(snake, newPart);
            }
            grow = FALSE;
            while(curr != NULL)
            {  
                Snake* part = (Snake*)getData(curr);
                /*Head movement*/
                if(curr == snake->head)
                {
                    temp = *part;
                    part->ROW -= 1;
                    part->symbol = '^';
                }
                /*Body movement*/
                else
                {   
                    new = *part;
                    part->ROW = temp.ROW;
                    part->COL = temp.COL;
                    temp = new;
                    if(curr->next != NULL)
                    {
                        if(part->COL == temp.COL)
                        {
                            part->symbol = '|';
                        }
                        else
                        {
                            part->symbol = '-';
                        }
                    }
                    else
                    {
                        part->symbol = '#';
                    }    
                }
                curr = curr->next;
            }
        }
        else
        {
            *errorMessage = "Hitting the border\n";
        }
            break;
        case 'a':
        if(head.COL == body.COL + 1) /* Check to see if the body of the snake is behind the head and if so prevent the move from happening */
        {
            *errorMessage = "You cannot go backwards\n";
        }
        else if(head.COL > 0) /* Main movement */
        {
            LinkedListNode* curr = snake->head;
            Snake temp;
            Snake new;

            if(grow == TRUE)    /*If the snake has eaten food then grow*/
            {
                Snake* newPart = (Snake*)malloc(sizeof(Snake));
                newPart->COL = head.COL - 1;
                newPart->ROW = head.ROW;
                newPart->symbol = '<';
                insertLast(snake, newPart);
            }
            grow = FALSE;
            
            while(curr != NULL)
            {  
                Snake* part = (Snake*)getData(curr);
                /*Head movement*/
                if(curr == snake->head)
                {
                    temp = *part;
                    part->COL -= 1;
                    part->symbol = '<';
                }
                /*Body movement*/
                else
                {   
                    new = *part;
                    part->ROW = temp.ROW;
                    part->COL = temp.COL;
                    temp = new;

                    if(curr->next != NULL)
                    {
                        if(part->COL == temp.COL)
                        {
                            part->symbol = '|';
                        }
                        else
                        {
                            part->symbol = '-';
                        }
                    }
                    else
                    {
                        part->symbol = '#';
                    }
                }
                curr = curr->next; 
            }
        }
        else
        {
            *errorMessage = "Hitting the border\n";
        }
            break;
        case 's':
        if(head.ROW == body.ROW - 1) /* Check to see if the body of the snake is behind the head and if so prevent the move from happening */
        {
            *errorMessage = "You cannot go backwards\n";
        }
        else if(head.ROW < ROWS - 3) /* Main movement */
        { 
            LinkedListNode* curr = snake->head;
            Snake temp;
            Snake new;

            if(grow == TRUE)    /*If the snake has eaten food then grow*/
            {
                Snake* newPart = (Snake*)malloc(sizeof(Snake));
                newPart->COL = head.COL;
                newPart->ROW = head.ROW + 1;
                newPart->symbol = 'v';
                insertLast(snake, newPart);
            }
            grow = FALSE;

            while(curr != NULL)
            {  
                Snake* part = (Snake*)getData(curr);
                /*Head movement*/
                if(curr == snake->head)
                {
                    temp = *part;
                    part->ROW += 1;
                    part->symbol = 'v';
                }
                /*Body movement*/
                else
                {   
                    new = *part;
                    part->ROW = temp.ROW;
                    part->COL = temp.COL;
                    temp = new;

                    if(curr->next != NULL)
                    {
                        if(part->COL == temp.COL)
                        {
                            part->symbol = '|';
                        }
                        else
                        {
                            part->symbol = '-';
                        }
                    }
                    else
                    {
                        part->symbol = '#';
                    }
                }
                curr = curr->next; 
            }
            
        }
        else
        {
            *errorMessage = "Hitting the border\n";
        }      
            break;        
        case 'd':
        if(head.COL == body.COL - 1) /* Check to see if the body of the snake is behind the head and if so prevent the move from happening */
        {
            *errorMessage = "You cannot go backwards\n";
        }
        else if(head.COL < COLS - 3) /* Main movement */
        {
            LinkedListNode* curr = snake->head;
            Snake temp;
            Snake new;

            if(grow == TRUE)    /*If the snake has eaten food then grow*/
            {
                Snake* newPart = (Snake*)malloc(sizeof(Snake));
                newPart->COL = head.COL + 1;
                newPart->ROW = head.ROW;
                newPart->symbol = '>';
                insertLast(snake, newPart);
            }
            grow = FALSE;

            while(curr != NULL)
            {  
                Snake* part = (Snake*)getData(curr);
                /*Head movement*/
                if(curr == snake->head)
                {
                    temp = *part;
                    part->COL += 1;
                    part->symbol = '>';
                }
                /*Body movement*/
                else
                {   
                    new = *part;
                    part->ROW = temp.ROW;
                    part->COL = temp.COL;
                    temp = new;

                    if(curr->next != NULL)
                    {
                        if(part->COL == temp.COL)
                        {
                            part->symbol = '|';
                        }
                        else
                        {
                            part->symbol = '-';
                        }
                    }
                    else
                    {
                        part->symbol = '#';
                    }
                }
                curr = curr->next; 
            }
        }
        else
        {
            *errorMessage = "Hitting the border\n";
        }
            break;
        default:
            *errorMessage = "Error input\n";
            break;
    }
}

/*Reads the input file and adds the snake to the array from file*/
void readFile(char* fileName, int* ROWS, int* COLS, LinkedList* snake)
{
    FILE * fp = fopen(fileName, "r");

    int done = FALSE;
    if(fp == NULL)
    {
        perror("Error opening the file");
    }
    else
    {
        fscanf(fp, "%d %d", ROWS, COLS);
        while(!done)
        {
            Snake* part = (Snake*)malloc(sizeof(Snake));
            char symbol;
            int snakeX, snakeY;

            fscanf(fp, "%d %d %c", &snakeX, &snakeY, &symbol);
            
            part->ROW = snakeX;
            part->COL = snakeY;
            part->symbol = symbol;

            insertStart(snake, part);

            if(fgetc(fp) == EOF)
            {
                done = TRUE;
            }

            if(ferror(fp))
            {
                perror("Error reading from file");
            }
        }
        fclose(fp);      
    }
}