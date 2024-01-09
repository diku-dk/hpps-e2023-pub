CC=gcc
CFLAGS=-Wall -Wextra -pedantic
PROGRAMS=threads fork parent

all: $(PROGRAMS)

%: %.c
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(PROGRAMS)