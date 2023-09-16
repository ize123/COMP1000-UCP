CC = gcc
CFLAGS = -Wall -pedantic -ansi
OBJ = main.o game.o terminal.o random.o linkedlist.o
EXEC = snake

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : game.c terminal.h random.h LinkedList.h
	$(CC) -c main.c $(CFLAGS)

game.o : game.c LinkedList.h
	$(CC) -c game.c $(CFLAGS)

linkedlist.o : linkedlist.c LinkedList.h
	$(CC) -c linkedlist.c $(CFLAGS)

terminal.o : terminal.c terminal.h
	$(CC) -c terminal.c $(CFLAGS)

random.o : random.c random.h
	$(CC) -c random.c $(CFLAGS)

clean:
	rm -f $(EXEC) $(OBJ)