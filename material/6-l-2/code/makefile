CC=gcc
CFLAGS=-Wall -Wextra -pedantic
PROGRAMS=hello sharing badcount goodcount

all: $(PROGRAMS)

%: %.c
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(PROGRAMS)