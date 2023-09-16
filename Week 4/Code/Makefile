CC = gcc
CFLAGS = -Wall -pedantic -ansi
OBJ = numbers.o order.o user_input.o
EXEC = numbers

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

numbers.o : numbers.c order.h user_input.h
	$(CC) -c numbers.c $(CFLAGS)

order.o : order.c order.h
	$(CC) -c order.c $(CFLAGS)

user_input.o : user_input.c user_input.h
	$(CC) -c user_input.c $(CFLAGS)

clean : 
	rm -f $(EXEC) $(OBJ)

