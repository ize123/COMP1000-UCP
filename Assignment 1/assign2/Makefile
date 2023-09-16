CC = gcc
CFLAGS = -Wall -pedantic -ansi
OBJ = main.o game.o terminal.o random.o
EXEC = snake


ifdef UNBEATABLE
CFLAGS += -D UNBEATABLE
UNBEATABLE : clean $(EXEC)
endif

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : game.h terminal.h random.h
	$(CC) -c main.c $(CFLAGS)

game.o : game.c game.h
	$(CC) -c game.c $(CFLAGS)

terminal.o : terminal.c terminal.h
	$(CC) -c terminal.c $(CFLAGS)

random.o : random.c random.h
	$(CC) -c random.c $(CFLAGS)

clean:
	rm -f $(EXEC) $(OBJ)
