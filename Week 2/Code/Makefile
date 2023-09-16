CC = gcc
CFLAGS = -Wall -pedantic -ansi
OBJ = bounds.o powers.o
EXEC = bounds

$(EXEC) : $(OBJ)
		$(CC) $(OBJ) -o $(EXEC)

bounds.o : bounds.c macros.h powers.h
		$(CC) -c bounds.c $(CFLAGS)

powers.o : powers.c powers.h
		$(CC) -c powers.c $(CFLAGS)

clean : 
		rm -f $(EXEC) $(OBJ)

