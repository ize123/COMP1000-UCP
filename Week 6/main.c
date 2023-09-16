#include <stdio.h>
#include <stdlib.h>
#include "entry.h"

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("Incorrect arguments\n");
    }
    else
    {
        FILE * fp = fopen("sample.txt", "r");
        int index = atoi(argv[1]);
        int i;
        if(fp == NULL)
        {
            perror("Error opening the file");
        } 
        else
        {
            int done = FALSE;
            int day, month, year, size;
            int count = 0;
            entry* arr;
            fscanf(fp, "%d", &size);
            arr = malloc(size * sizeof(entry));

            while(!done)
            {   
                char* message  = (char*)malloc(sizeof(char) * 100);
                fscanf(fp, "%d/%d/%d\n", &day, &month, &year);
                fgets(message, 100, fp);
            
                arr[count].date.day = day;
                arr[count].date.month = month;
                arr[count].date.year = year;
                arr[count].message = message;
            
            
                count ++;
                if(count == size)
                {
                    done = TRUE;
                }
            
            }
            printf("%d-%02d-%02d: %s", arr[index].date.year, arr[index].date.month, arr[index].date.day, arr[index].message);

            for(i = 0; i < size; i++)
            {
               free(arr[i].message);
            }
            free(arr);
        }
        fclose(fp);
        fp = NULL;
    }
    return 0;
}
