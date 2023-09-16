CC = gcc
CFLAGS = -Wall -pedantic -ansi
OBJ = main.o
EXEC = prac6

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o :  entry.h
	$(CC) -c main.c $(CFLAGS)

clean:
	rm -f $(EXEC) $(OBJ)