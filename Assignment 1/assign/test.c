#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 20

int main(void)
{
    int i, j;
    int intArray[ROWS][COLS];
    for(i =0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            intArray[i][j] = i * j;
            printf("%d ", intArray[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}
