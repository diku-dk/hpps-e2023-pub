CC=cc
CFLAGS=-Wall -Wextra -pedantic

test_fibs: fibs.o test_fibs.o
	$(CC) fibs.o test_fibs.o -o test_fibs

fibs.o: fibs.c
	$(CC) -c fibs.c $(CFLAGS)

test_fibs.o: test_fibs.c
	$(CC) -c test_fibs.c $(CFLAGS)
