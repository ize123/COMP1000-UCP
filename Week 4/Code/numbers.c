#include <stdio.h>
#include "order.h"
#include "user_input.h"

int main()
{
    int x,y,z;
    char char1;
    FptrType fnPtr;
    readInts(&x, &y, &z, &char1);
    fnPtr = order(char1);
    
    printf("Before function operations X is: %d Y is: %d and Z is: %d\n", x, y, z);
    printf("FUNCTION OPERATIONS\n");
    (*fnPtr)(&x, &y, &z);
    printf("After function X is: %d and Y is: %d and Z is: %d\n", x, y, z);

    return 0;
}
