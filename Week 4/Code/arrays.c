#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrays.h"
#define LEN 10

int main(int argc, char* argv[])
{
    int intArr[LEN];
    int tempArr[LEN];
    int i;
    if(argc < 2)
    {
        printf("Error need to have more than 1 argument\n");
    }
    else if(strcmp(argv[1], "sum") == 0)
    {
        convert(argv, intArr, argc);
        printf("%d\n", sum(intArr, argc));
    }
    else if(strcmp(argv[1], "max") == 0)
    {
        convert(argv, intArr, argc);
        printf("%d\n" ,max(intArr, argc));
    }
    else if(strcmp(argv[1], "reverse") == 0)
    {
        convert(argv, intArr, argc);
        for(i = 0; i < argc-2; i++)
        {
            tempArr[i] = intArr[i+2];
            printf("%d\n", tempArr[i]);
        }
        reverse(tempArr, argc-2);
        arrayOutput(tempArr, argc-2);
    }
    else
    {
        printf("ERROR Incorrect arguments");
    }
    return 0;
}

int sum(int intArr[], int length)
{
    int i;
    int total = 0;
    for(i = 0; i < length; i++)
    {
        total += intArr[i];
    }
    return total;
}

int max(int intArr[], int length)
{
    int i;
    int max = 0;
    int index;
    for(i = 0; i < length; i++)
    {
        if(intArr[i] > max)
        {
            max = intArr[i];
            index = i - 1;
        } 
    }
    return index;
}

void reverse(int intArr[], int length)
{
    int i;
    int temp; 
    for(i = 0; i < (length/2); i++)
    {
        temp = intArr[i];
        intArr[i] = intArr[length - i - 1];
        intArr[length - i - 1] = temp;
    }
}

void convert(char* arr[], int intArr[], int length)
{
    int i;
    int value;
    for(i = 0; i < length; i++)
    {
        value = atoi(arr[i]);
        intArr[i] = value;
    }
}

void arrayOutput(int arr[], int length)
{   
    int i;
    printf("{");
    for(i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("}\n");
}
