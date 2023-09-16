#ifndef GAME_H
#define GAME_H

#define FALSE 0
#define TRUE !FALSE

void printMap(int**, int, int, int*, int*, int, int, int);
void initializeSnake(int*, int*, int);
void move(int, int, char, int*, int*, int, char**);
int checkLose(int*, int*, int);
int checkWin(int*, int*, int, int, int);
#endif
