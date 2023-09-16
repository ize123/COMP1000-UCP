#include <stdio.h>
#include "order.h"

void ascending2(int* x, int* y)
{
    if(*x > *y)
    {
        int temp;
        temp = *x;
        *x = *y;
        *y = temp;
    }
}

void ascending3(int* x, int* y, int*z)
{
    ascending2(x,y);
    ascending2(y,z);
    ascending2(x,y);
}

void descending2(int* x, int* y)
{
    if(*x < *y)
    {
        int temp;
        temp = *x;
        *x = *y;
        *y = temp;
    }
}
void descending3(int* x, int* y, int* z)
{
        descending2(x,y);
        descending2(y,z);
        descending2(x,y);
}

FptrType order(char c)
{
    FptrType retVal = NULL;
    if(c =='A')
    {
        retVal = &ascending3;
    }
    else if( c == 'D')
    {
        retVal = &descending3;
    }
    return retVal;
}
