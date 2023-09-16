#ifndef ORDER_H
#define ORDER_H

typedef void (*FptrType)(int*, int*, int*);

void ascending2(int* x, int* y);
void ascending3(int* x, int* y, int* z);
void descending2(int* x, int* y);
void descending3(int* x, int* y, int* z);
FptrType order(char);

#endif
