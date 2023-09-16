CC = gcc
CFLAGS = -Wall -pedantic -ansi
OBJ = numbers.o order.o
EXEC = numbers

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

numbers.o : numbers.c order.h
	$(CC) - c numbers.c $(CFLAGS)

order.o : order.c order.h
	$(CC) -c order.c $(CFLAGS)

clean : 
	rm -f $(EXEC) $(OBJ)

