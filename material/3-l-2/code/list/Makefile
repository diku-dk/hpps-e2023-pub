CC=cc
CFLAGS=-Wall -Wextra -pedantic -fsanitize=address -g

test_list: list.o test_list.o
	$(CC) -o test_list list.o test_list.o $(CFLAGS)

list.o: list.c
	$(CC) -c list.c $(CFLAGS)

test_list.o: test_list.c
	$(CC) -c test_list.c $(CFLAGS)
