CC=gcc
CFLAGS=-Wall -Wextra -pedantic -fopenmp
PROGRAMS=openmp-example

all: $(PROGRAMS)

%: %.c
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(PROGRAMS)