#include <stdio.h>
#include "powers.h"

int powers()
{
    static int x = 1;
    x = x * 2;
    return x;
}
