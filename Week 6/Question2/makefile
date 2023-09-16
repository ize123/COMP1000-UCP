CC = gcc
CFLAGS = -Wall -pedantic -ansi
OBJ = LinkedListTest.o
EXEC = testLinkedList

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

LinkedListTest.o :  linkedlist.c LinkedList.h
	$(CC) -c LinkedListTest.o.c $(CFLAGS)

clean:
	rm -f $(EXEC) $(OBJ)