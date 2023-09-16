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
        ROWS = atoi(argv[1]) + 2;
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
        
        /* Game Logic */
        system("clear");
        initializeSnake(snakeX, snakeY, LENGTH);
        foodX = random(2,ROWS - 2);
        foodY = random(1, COLS - 2);
        printMap(field, ROWS, COLS, snakeX, snakeY, LENGTH, foodX, foodY);
        while(!GAME_END && !GAME_WIN)
        {
            char input;
            disableBuffer();
            scanf("%c", &input);
            enableBuffer();
            system("clear");
            move(ROWS, COLS, input, snakeX, snakeY, LENGTH);
            GAME_END = checkLose(snakeX, snakeY, LENGTH);
            GAME_WIN = checkWin(snakeX, snakeY, LENGTH, foodX, foodY);
            printMap(field, ROWS, COLS, snakeX, snakeY, LENGTH, foodX, foodY);
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
        free(field);
        free(snakeX);
        free(snakeY);
    }
    return 0;
}

void printMap(int** array, int ROWS, int COLS, int* snakeX, int* snakeY, int LENGTH, int foodX, int foodY)
{
    int i, j;
    for(i = 0; i < ROWS; i++)
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

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            if(i == foodX && j == foodY)
            {
                array[i][j] = '@';
            }
        }
    }

    for(i = 0; i < LENGTH; i++)
    {
        int x, y;
        x = snakeX[i];
        y = snakeY[i];

        if(i == 0) /* Tail of the snake */
        {
            array[x][y] = '#';
        }
        else if( i == LENGTH - 1) /* Which symbol to use for the head */
        {
            if(snakeX[i - 1] > snakeX[i])
            {
                array[x][y] = '^';
            }
            else if(snakeX[i - 1] < snakeX[i])
            {
                array[x][y] = 'v';
            }
            else if(snakeY[i - 1] > snakeY[i])
            {
                array[x][y] = '<';
            }
            else
            {
                array[x][y] = '>';
            }
        }
        else /* Which body part to use for th  snake */
        {
            if(snakeX[i - 1] == snakeX[i])
            {
                array[x][y] = '-';
            }
            else
            {
                array[x][y] = '|';
            }
        }
    }

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            printf("%c", array[i][j]);
        }
        printf("\n");
    }
}

void initializeSnake(int* snakeX, int* snakeY, int LENGTH)
{
    int i;
    for(i = 0; i < LENGTH; i++)
    {
        snakeX[i] = 1;
        snakeY[i] = i + 1;
    }
}

void move(int ROWS, int COLS, char input, int* snakeX, int* snakeY, int LENGTH)
{
    int i;
    switch(input)
    {
        case 'w':
        if(snakeX[LENGTH - 1] == snakeX[LENGTH - 2] + 1)
        {
            printf("You cannot go backwards\n");
        }
        else if(snakeX[LENGTH - 1] + 1 > 2)
        {
            for(i = 0; i < LENGTH; i++)
            {
                if(i == LENGTH - 1)
                {
                    snakeX[i] = snakeX[i] - 1;
                }
                else
                {
                    snakeX[i] = snakeX[i + 1];
                    snakeY[i] = snakeY[i + 1];
                }
            }
        }
        else
        {
            printf("hitting the border\n");
        }
            break;

        case 'a':
        if(snakeY[LENGTH - 1] == snakeY[LENGTH -2] + 1)
        {
            printf("You cannot go backwards\n");
        }
        else if(snakeY[LENGTH - 1] - 1 > 0)
        {
            for(i = 0; i < LENGTH; i++)
            {
                if( i == LENGTH - 1)
                {
                    snakeY[i] = snakeY[i] - 1;
                }
                else
                {
                    snakeX[i] = snakeX[i + 1]; 
                    snakeY[i] = snakeY[i + 1];
                }
            }
        }
        else
        {
            printf("hitting the border\n");
        }
            break;
        
        case 's':
        if(snakeX[LENGTH - 1] == snakeX[LENGTH - 2] - 1)
        {
            printf("You cannot go backwards\n");
        }
        else if(snakeX[LENGTH - 1] + 1 < ROWS - 1)
        {
            for(i = 0; i < LENGTH; i++)
            {
                if(i == LENGTH - 1)  
                {
                    snakeX[i] = snakeX[i] + 1;
                }
                else
                {
                    snakeX[i] = snakeX[i + 1];
                    snakeY[i] = snakeY[i + 1];
                }
            }
        }
        else
        {
           printf("Hitting the border\n");
        }
            break;
        
        case 'd':
        if(snakeY[LENGTH - 1] == snakeY[LENGTH - 2] - 1)
        {
            printf("You cannot go backwards\n");
        }
        else if(snakeY[LENGTH - 1] + 1 < COLS - 1)
        {
            for(i = 0; i < LENGTH; i++)
            {
                if(i == LENGTH - 1)
                {
                    snakeY[i] = snakeY[i] + 1;
                }
                else
                {
                    snakeX[i] = snakeX[i + 1];
                    snakeY[i] = snakeY[i + 1];
                }
            }
        }
        else
        {
            printf("Hitting the border\n");
        }
            break;
        default:
            printf("Error input\n");
    }
}

int checkLose(int* snakeX, int* snakeY, int LENGTH)/* Check to see if th snake has touched its own body causing a loss condition */
{
    int i;
    int lose = FALSE;
    for(i = 0; i < LENGTH - 2; i++)
    {
        if(snakeX[LENGTH - 1] == snakeX[i] && snakeY[LENGTH - 1] == snakeY[i])
        {
            lose = TRUE;
        }
    }
    return lose;
}

int checkWin(int* snakeX, int* snakeY, int LENGTH, int foodX, int foodY)
{
    int win = FALSE;

    if(snakeY[LENGTH - 1] == foodY && snakeX[LENGTH - 1] == foodX)
    {
        win = TRUE;
    }
    return win;
}


