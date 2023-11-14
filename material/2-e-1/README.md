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
