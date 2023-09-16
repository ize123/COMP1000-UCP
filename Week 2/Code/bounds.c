#include <stdio.h>
#include "macros.h"
#include "powers.h"

int main(void)
{
    int input; 

    printf("%d\n", BETWEEN(3,6,5));
    printf("%d\n", BETWEEN(3.0,4.0,5.0));
    printf("%d\n", BETWEEN('A', 'B', 'C'));

    printf("Please enter a number");
    scanf("%d", &input);
    if(BETWEEN(1, 31, input))
    {
        int i;
        for(i = 0; i < input; i++)
        {
            printf("%d\n", powers());
        }
    }
    return 0;
}
