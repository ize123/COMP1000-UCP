#include <stdio.h>

void readInts(int* int1, int* int2, int* int3, char* pCh)
{
    printf("Please enter a number: ");
    scanf("%d", int1);
    
    printf("Please enter another number: ");
    scanf("%d", int2);

    printf("Please enter another number: ");
    scanf("%d", int3);

    printf("Please enter 'A' or 'D': ");
    scanf(" %c",pCh);
}
