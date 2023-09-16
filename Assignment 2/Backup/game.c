#include <stdio.h>
#include <stdlib.h>
#include "game.h"

/*Method used to print the current state of the map*/
void printMap(int** array, int ROWS, int COLS, int* snakeY, int* snakeX, int LENGTH, int foodX, int foodY)
{
    int i, j;
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

    for(i = 0; i < ROWS; i++) /* Draw the food */
    {
        for(j = 0; j < COLS; j++)
        {
            if(i == foodX && j == foodY)
            {
                array[i][j] = '@';
            }
        }
    }
    
    /*Check for the positions of the snake currently on the map*/
    for(i = 0; i < LENGTH; i++)
    {
        int x, y;
        x = snakeY[i];
        y = snakeX[i];

        if(i == 0) /* Tail of the snake */
        {
            array[x][y] = '#';
        }
        else if( i == LENGTH - 1) /* Which symbol to use for the head using the position of the bodyrelative to the head */
        {
            if(snakeY[i - 1] > snakeY[i])
            {
                array[x][y] = '^';
            }
            else if(snakeY[i - 1] < snakeY[i])
            {
                array[x][y] = 'v';
            }
            else if(snakeX[i - 1] > snakeX[i])
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
            if(snakeY[i - 1] == snakeY[i])
            {
                array[x][y] = '-';
            }
            else
            {
                array[x][y] = '|';
            }
        }
    }

    for(i = 0; i < ROWS; i++) /* Print out all the symbols that are stored on the array */
    {
        for(j = 0; j < COLS; j++)
        {
            printf("%c", array[i][j]);
        }
        printf("\n");
    }
}

/* Initialisation of the snake at the beginning of the program*/
void initializeSnake(int* snakeY, int* snakeX, int LENGTH)
{
    int i;
    for(i = 0; i < LENGTH; i++)
    {
        snakeY[i] = 1;
        snakeX[i] = i + 1;
    }
}

/* Method for moving the snake around the map */
void move(int ROWS, int COLS, char input, int* snakeY, int* snakeX, int LENGTH, char** errorMessage)
{
    int i;
    *errorMessage = "";
    switch(input)
    {
        case 'w':
        if(snakeY[LENGTH - 1] == snakeY[LENGTH - 2] + 1) /* Check to see if the body of the snake is behind the head and if so prevent the move from happening */
        {
            *errorMessage = "You cannot go backwards\n";
        }
        else if(snakeY[LENGTH - 1] + 1 > 2) /* Main movement */
        {
            for(i = 0; i < LENGTH; i++)
            {
                if(i == LENGTH - 1) /* if it is the head then decrease the Y position by 1 */
                {
                    snakeY[i] = snakeY[i] - 1;
                }
                else /* Else shuffle the body along */
                {
                    snakeY[i] = snakeY[i + 1];
                    snakeX[i] = snakeX[i + 1];
                }
            }
        }
        else
        {
            *errorMessage = "Hitting the border\n";
        }
            break;

        case 'a':
        if(snakeX[LENGTH - 1] == snakeX[LENGTH -2] + 1)
        {
            *errorMessage = "You cannot go backwards\n";
        }
        else if(snakeX[LENGTH - 1] - 1 > 0)
        {
            for(i = 0; i < LENGTH; i++)
            {
                if( i == LENGTH - 1) /* If it is the head decrement X positio n by 1 */
                {
                    snakeX[i] = snakeX[i] - 1;
                }
                else
                {
                    snakeY[i] = snakeY[i + 1]; 
                    snakeX[i] = snakeX[i + 1];
                }
            }
        }
        else
        {
            *errorMessage = "Hitting the border\n";
        }
            break;
        
        case 's':
        if(snakeY[LENGTH - 1] == snakeY[LENGTH - 2] - 1)
        {
            *errorMessage = "You cannot go backwards\n";
        }
        else if(snakeY[LENGTH - 1] + 1 < ROWS - 1)
        {
            for(i = 0; i < LENGTH; i++) /* If it is the head incremenet the y position b 1 */
            {
                if(i == LENGTH - 1)  
                {
                    snakeY[i] = snakeY[i] + 1;
                }
                else
                {
                    snakeY[i] = snakeY[i + 1];
                    snakeX[i] = snakeX[i + 1];
                }
            }
        }
        else
        {
           *errorMessage = "Hitting the border\n";
        }
            break;
        
        case 'd':
        if(snakeX[LENGTH - 1] == snakeX[LENGTH - 2] - 1)
        {
            *errorMessage = "You cannot go backwards\n";
        }
        else if(snakeX[LENGTH - 1] + 1 < COLS - 1)
        {
            for(i = 0; i < LENGTH; i++) /* If it is the head increment the x position by 1 */
            {
                if(i == LENGTH - 1)
                {
                    snakeX[i] = snakeX[i] + 1;
                }
                else
                {
                    snakeY[i] = snakeY[i + 1];
                    snakeX[i] = snakeX[i + 1];
                }
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

/* Check to ee if the snake has touched it own body causing a loss */
int checkLose(int* snakeY, int* snakeX, int LENGTH)
{
    int i;
    int lose = FALSE;
    for(i = 0; i < LENGTH - 2; i++)
    {
        if(snakeY[LENGTH - 1] == snakeY[i] && snakeX[LENGTH - 1] == snakeX[i])
        {
            lose = TRUE;
        }
    }
    return lose;
}

/* Check to see if the snake head is at the food meaning a win */
int checkWin(int* snakeX, int* snakeY, int LENGTH, int foodX, int foodY)
{
    int win = FALSE;

    if(snakeY[LENGTH - 1] == foodY && snakeX[LENGTH - 1] == foodX)
    {
        win = TRUE;
    }
    return win;
}


