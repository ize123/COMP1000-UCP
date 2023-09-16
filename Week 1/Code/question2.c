#include <stdio.h>

int main(void)
{
    int result, result2;
    printf("Enter an integer");
    scanf("%d", &result);
    printf("Enter a second integer");
    scanf("%d", &result2);

    if((result % result2) == 0)
    {
        printf("divisible\n");
    }
    else
    {
        printf("not divisible\n");
    }
    return 0;
}
