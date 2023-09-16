#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "terminal.h"
#include "random.h"

int main (int argc, char* argv[])
{
    /*Variable Initialisation*/
    int ROWS, COLS, i;
    int** field;
    LinkedList* snake;
    int foodX, foodY;
    char* errorMessage = " ";
    int score = 0;
    int goal;
    int GAME_WIN = FALSE;
    int SCORE = FALSE;
    int GROW = FALSE;
    char* fileName;

    /*Parameter Checking*/
    if(argc < 3)
    {
        printf("incorrect agurments. Program usage:\n<file_name> <food_amount_to_win> ");
    }
    else if(atoi(argv[2]) < 2 )
    {
        printf("<food_amount_to_win> must be a minimum of 2\n");
    }
    else
    {
        system("clear");
        /*Assigning variables to parameters*/
        fileName = argv[1];
        goal = atoi(argv[2]);

        /*Initialised linked list*/
        snake = createLinkedList();
        initRandom();

        /*Read in the Snake from the text file*/
        readFile(fileName, &ROWS, &COLS, snake);  

        foodX = Random(1,ROWS - 2); /* Random Number generator for snake food and ensures it does not spawn on the snake*/
        foodY = Random(1, COLS - 2);

        /*initialise field of play*/
        field = (int**)malloc((ROWS) * sizeof(int*));
        for(i = 0; i < ROWS; i++)
        {
            field[i] = (int*)malloc((COLS) * sizeof(int));
        }
        
        /*Print map for the first time*/
        printMap(field, ROWS, COLS, snake, foodX, foodY, score, goal);
        /*Main game loop*/
        while(!GAME_WIN)
        {
            char input;
            disableBuffer();
            scanf("%c", &input);
            enableBuffer();
            system("clear");

            move(ROWS, COLS, input, snake, &errorMessage, GROW);
            printMap(field, ROWS, COLS, snake, foodX, foodY, score, goal);
            SCORE = checkWin(foodX, foodY, snake);
            if(SCORE == TRUE)
            {
                score++;
                if(score == goal)
                {
                    GAME_WIN = TRUE;
                }
                foodX = Random(1,ROWS - 2);
                foodY = Random(1, COLS - 2);
                GROW = TRUE;
                SCORE = FALSE;
            }
            else
            {
                GROW = FALSE;
            }
            printf("%s", errorMessage);
        }
        if(GAME_WIN)
        {
            printf("Congratulations you win! :)\n");
        }


        /*Freeing all allocated memory*/
        for(i = 0; i < ROWS; i++)
        {
            free(field[i]);
        }

        free(field);

        freeLinkedList(snake);
    }
    return 0;
}