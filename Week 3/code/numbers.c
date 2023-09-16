#include <stdio.h>
#include "order.h"

int main()
{
    int x = 34;
    int y = 12;
    int z = 2;
    
    int a = 12;
    int b = 34;
    int c = 89;

    printf("Before everything X is: %d Y is: %d and Z is: %d", x, y, z);

    printf("Before ascending X is: %d and Y is: %d", x, y);
    ascending2(&x, &y);
    printf("After ascending X is: %d and Y is: %d", x, y);
    ascending3(&x, &y, &z);
    printf("After ascending X is: %d, Y is: %d and Z is: %d", x, y, z);

    descending2(&a, &b);
    descending3(&a, &b, &c);

    return 0;
}
