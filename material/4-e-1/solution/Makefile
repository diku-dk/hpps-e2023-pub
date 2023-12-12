CC?=cc
CFLAGS?=-Wall -Wextra -pedantic

all: names

names: names.o record.o
	$(CC) -o names names.o record.o

names.o: names.c
	$(CC) -c names.c $(CFLAGS)

record.o: record.c
	$(CC) -c record.c $(CFLAGS)
