CC=gcc

CFLAGS=-Wall -Werror -Wextra -std=c11

all : graph.o stack.o queue.o matrix.o shunting_yard.o tokens.o
	$(CC) graph.o stack.o queue.o matrix.o shunting_yard.o tokens.o -o ./../build/graph -lm
	rm -f *.o

graph.o : graph.c
	$(CC) $(CFLAGS) -c graph.c -o graph.o

stack.o : stack.c
	$(CC) $(CFLAGS) -c stack.c -o stack.o

queue.o : queue.c
	$(CC) $(CFLAGS) -c queue.c -o queue.o

matrix.o : matrix.c
	$(CC) $(CFLAGS) -c matrix.c -o matrix.o

shunting_yard.o: shunting_yard.c
	$(CC) $(CFLAGS) -c shunting_yard.c -o shunting_yard.o

tokens.o : tokens.c
	$(CC) $(CFLAGS) -c tokens.c -o tokens.o

clean :
	rm -f ./../build/Quest_*