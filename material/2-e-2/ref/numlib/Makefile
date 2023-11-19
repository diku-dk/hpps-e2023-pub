CFLAGS?=-std=c99 -Wall -Wextra -pedantic
CC?=cc

all: test

test: test.c numlib.c
	$(CC) test.c numlib.c -o test $(CFLAGS)

clean:
	rm -f test
