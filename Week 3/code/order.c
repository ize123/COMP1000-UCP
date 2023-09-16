#include <stdio.h>
#include "order.h"

static void ascending2(int* x, int* y)
{
    if(*x > *y)
    {
        int temp;
        temp = *x;
        *x = *y;
        *y = temp;
    }
}

static void ascending3(int* x, int* y, int*z)
{
    ascending2(x,y);
    ascending2(y,z);
    ascending2(x,y);
}

static void descending2(int* x, int* y)
{
    if(*x < *y)
    {
        int temp;
        temp = *x;
        *x = *y;
        *y = temp;
    }
}
static void descending3(int* x, int* y, int* z)
{
        descending2(x,y);
        descending2(y,z);
        descending2(x,y);
}
