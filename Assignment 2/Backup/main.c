#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "terminal.h"
#include "random.h"

int main(int argc, char* argv[])
{
    int i, ROWS, COLS, LENGTH;
    int** field;
    int* snakeX;
    int* snakeY;
    int foodX, foodY;
    int GAME_END = FALSE;
    int GAME_WIN = FALSE;
    char* errorMessage = " ";
    
    /* Checks to see if the program has the correct parameters */
    if(argc != 4)
    {
        printf("incorrect agurments. Program usage:\n./snake <row_map> <col_map> <snake_length>\n");
        
    }
    else if(atoi(argv[1]) < 5 || atoi(argv[2]) < 5)
    {
        printf("<row_map> and <col_map> must be a minimum of 5\n");
    }
    else if(atoi(argv[3]) < 3)
    {   
        printf("<snake_length> cannot be less than 3\n");
    }
    else if(atoi(argv[2]) < atoi(argv[3]))
    {
        printf("<snake_length> cannot be longer than <col_map>\n");
    }
    else
    {
        /* Initialize the arrays for the game */
        ROWS = atoi(argv[1]) + 2; /* +2 on each to account for the border */
        COLS = atoi(argv[2]) + 2;
        LENGTH = atoi(argv[3]);
        
        initRandom();
        
        field = (int**)malloc((ROWS) * sizeof(int*));
        snakeX = (int*)malloc((LENGTH) * sizeof(int));
        snakeY = (int*)malloc((LENGTH) * sizeof(int));
        
        for(i = 0; i < ROWS; i++)
        {
            field[i] = (int*)malloc((COLS) * sizeof(int));
        }
        
        system("clear");
        initializeSnake(snakeX, snakeY, LENGTH);
        foodX = Random(2,ROWS - 2); /* Random Number generator for snake food and ensures it does not spawn on the snake*/
        foodY = Random(1, COLS - 2);
        printMap(field, ROWS, COLS, snakeX, snakeY, LENGTH, foodX, foodY);
        /* Main game loop */
        while(!GAME_END && !GAME_WIN)
        {
            char input;
            disableBuffer();
            scanf("%c", &input);
            enableBuffer();
            system("clear");

            move(ROWS, COLS, input, snakeX, snakeY, LENGTH, &errorMessage);
            #ifndef UNBEATABLE
                GAME_END = checkLose(snakeX, snakeY, LENGTH);
            #endif
            GAME_WIN = checkWin(snakeX, snakeY, LENGTH, foodX, foodY);
            printMap(field, ROWS, COLS, snakeX, snakeY, LENGTH, foodX, foodY);
            printf("%s", errorMessage);
            /*move(ROWS, COLS, input, snakeX, snakeY, LENGTH);*/
        }
        if(GAME_END)
        {
            printf("You lose :(\n");
        }
        
        if(GAME_WIN)
        {
            printf("Congratulations you win! :)\n");
        }
        
        /* Freeing the mallocd arrays */
        for(i = 0; i < ROWS; i++)
        {
            free(field[i]);
        }
        free(field);
        free(snakeX);
        free(snakeY);
    }
    return 0;
}
