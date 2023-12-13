CC=gcc
CFLAGS=-Wall -Wextra -pedantic
PROGRAMS=forkbomb print_address virtual_write virtual_claim

all: $(PROGRAMS)

%: %.c
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(PROGRAMS)