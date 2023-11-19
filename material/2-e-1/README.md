# Exercises

## Play with integers

Here it is! The sequel to the [Integer representation
game](http://topps.diku.dk/compsys/integers.html)!

Make a winning streak at the [integer arithmetic
game](http://topps.diku.dk/compsys/integer-arithmetic.html). Then push
your skills to the limit by winning the [floating point
game](http://topps.diku.dk/compsys/floating-point.html).

## Developing a C library for reading and writing numbers

Now that we understand how integers and floating-point numbers are
represented, let us create a C library for reading and writing them to
files. Such a library will be the topic of A2. This and [the
other](../2-e-2) set of exercises are intended to prepare you for A2,
by teaching you how to structure real C libraries generally, and in
particular how the library you will work on for A2 will work.

In A1 we put all code in the header file (`bits.h`). Such [header-only
libraries](https://en.wikipedia.org/wiki/Header-only) have their
merits, but also serious downsides. In particular, they cannot be
accessed by other languages, such as Python.

Most real C libraries are structured as one or more header files and
one or more *implementation files* (`.c` files). The difference
between such implementation files and the C programs you have written
previously is that *they have no `main()` function*. Next week we will
see how this enables us to compile a library *once* and use it
*multiple times*. For now, we will simply pass multiple `.c` files to
the compiler.

The [`ref`](ref/) directory contains our solutions. It's best to look
at them only when you have tried yourself first, or are stuck. When
you do look at them, make sure you understand why they work before
moving on.

### Part 1: Setting up a working environment

* Create an empty file `numlib.h` containing the following *prototype*:

  ```C
  int get_number(void);
  ```

  In C, a prototype is a declaration that some function *exists*, but
  without giving it a definition. Think of it like an abstract
  interface.

* Create a file `numlib.c` that contains `#include "numlib.h"` and the
  following *definition*:

  ```C
  int get_number(void) {
    return 42;
  }
  ```

* Create a file `numlib_test.c`.

  This file must contain `#include "numlib.h"` and a `main()`
  function. The `main()` function should call `get_number()` and print
  the result.

* Create a `Makefile` with a target `numlib_test` that compiles
  `numlib.c` *and* `numlib_test.c` (by passing both to the C compiler)
  to produce a program called `numlib`. Look at [last week's
  exercises](../1-e-2) or A1 if you have forgotten what that looks
  like.

Now run `make numlib_test` and run `./numlib_test` to ensure
everything works. You have now created your first multi-file C
program.

#### Hints

* **Never** `#include` a `.c` file! If you ever do something like
  `#include "numlib.c"`, then you are making a mistake. Pass the `.c`
  files to the *compiler* on the command line, or in your `Makefile`.

* [Solution here](ref/part1).

### Part 2: A very crude number reader

The following function reads a single character from standard input
(the console, unless redirected). If that character corresponds to a
decimal digit, it returns an `int` of the corresponding numeric value.
Otherwise it returns -1.

```C
int get_digit(void) {
  int c = getchar();
  if (isdigit(c)) {
    return c - 48;
  } else {
    return -1;
  }
}
```

We will use this function to make `get_number()` return an integer
read from standard input. Now go through the following steps. Remember
to check after every step that everything still compiles.

* Copy `get_digit` into `numlib.c` but *not* `numlib.h`. You will need
  to add includes for the the `stdio.h` and `ctype.h` headers.

* Now modify `get_number` such that it contains a loop that repeatedly
  calls `get_digit()` and produces a number corresponding to the
  digits read. The loop should terminate (and `get_number()` return)
  when `get_digit()` returns -1.

* Modify `numlib_test.c` such that it calls `get_number()` twice (and
  prints both numbers, of course).

Now ponder:

* Can `numlib_test.c` directly use `get_digit()`? Why or why not? What
  would you modify if you wanted this to be possible?

* What happens when you run `echo "123 456" | ./numlib_test`?

* What happens when you run `echo "123  456" | ./numlib_test`?
