#ifndef STRUCT_H
#define STRUCT_H

#define FALSE 0
#define TRUE !FALSE

    typedef struct date{
        int day;
        int month;
        int year;
    } date;

    typedef struct entry {
        date date;
        char* message;
    } entry;

#endif