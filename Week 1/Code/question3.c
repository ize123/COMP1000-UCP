#include <stdio.h>
int factorial(int number);

int main(void)
{
    int number;
    printf("Please enter a number ");
    scanf("%d", &number);
    if(number >= 0)
    {
        factorial(number);
    }
    return 0;
}

int factorial(int n)
{
    int count, fact = 1;
    if(n == 0)
    {
        fact = 1;
        printf("\nFactorial of %d is %d\n", n, fact);
    }
    else
    {
        for(count = 1; count <= n; count++)
        {
            fact = fact * count;
        }
        printf("\nFactorial of %d is %d\n", n, fact);
    }
    return 0;
}
