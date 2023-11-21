CFLAGS?=-std=c99 -Wall -Wextra -pedantic
CC?=cc

all: test uint_ascii_to_uint_le uint_le_to_uint_ascii

test: test.c numlib.c
	$(CC) test.c numlib.c -o test $(CFLAGS)

uint_ascii_to_uint_le: uint_ascii_to_uint_le.c numlib.c
	$(CC) uint_ascii_to_uint_le.c numlib.c -o uint_ascii_to_uint_le $(CFLAGS)

uint_le_to_uint_ascii: uint_le_to_uint_ascii.c numlib.c
	$(CC) uint_le_to_uint_ascii.c numlib.c -o uint_le_to_uint_ascii $(CFLAGS)

clean:
	rm -f test
