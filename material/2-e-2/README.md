# Exercises

These exercises continue [the previous ones](../2-e-1). Now we will
begin to build a library that actually behaves like production-ready
code should, which particularly involves proper error detection.

But first, we will build a useful tool that might come in handy. This
will also give you more experience with C, in particular with file I/O
and simple use of pointers.

The [`ref`](ref/) directory contains our solutions. It's best to look
at them only when you have tried yourself first, or are stuck. When
you do look at them, make sure you understand why they work before
moving on.

As always, we will follow good practice and always create `Makefile`s
to automate compilation.

In the following, we colloquially use "print" as slang for writing to
standard output.

## A hex dumper

Write a C program `hexabyte` that prints in hexadecimal notation the
bytes contained in a file.  For example:

```
$ ./hexabyte ints.bin
01
00
00
00
01
00
00
00
02
00
00
00
03
...
```

### Hints

* Define the main function as

  ```C
  int main(int argc, char** argv) {
    ...
  }
  ```

  in order to access command-line parameters (in `argv`).

* Use `fopen(filename, "r")` to open a file for reading.

* Use the `fread()` function to actually perform the read from the
  `FILE*` object.  This function will return `0` when you have read
  the entire file.

* Use `%.2x` format specifier with `printf()` to print an integer as a
  two-digit hexadecimal number.

* Use the `assert` macro from `<assert.h>` to guard against potential
  errors.

* You *did* create a `Makefile`, right?

## Working on `numlib`

Take the code developed in the Tuesday exercises, but delete the code
from `numlib.h` and `numlib.c` (and any test programs you may have
written) - we start from scratch.

Add the following includes to `numlib.h`:

```
#include <stdint.h>
#include <stdio.h>
```

Add the following includes to `numlib.c`:

```C
#include "numlib.h"
#include <stdint.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
```

Also add the following function to `numlib.c` and a corresponding
prototype to `numlib.h`:

```C
void skipspaces(FILE *f) {
  while (1) {
    int c = fgetc(f);
    if (!isspace(c)) {
      if (c != EOF) {
        ungetc(c, f);
      }
      return;
    }
  }
}
```

What do you think it does?

<details>
<summary>Open this to see the answer</summary>

The `skipspaces()` function repeatedly reads characters from the given
file until it reads something that is *not* a whitespace character. It
then puts the character "back in the file" (so to speak) with
`ungetc()`, meaning that the next call to `fgetc()` will read it.
However, this is *only* done if the character is not the special `EOF`
marker.

Essentially, this function fast-forwards over any whitespace
characters, but is careful not to also consume the first
non-whitespace character encountered.

</details>

### Implementing `read_uint_ascii()`

Add the following prototype to `numlib.h`:

```C
// Read unsigned integer in base-10 ASCII format from the given file.
// Stores the resulting number in 'out'. Stops at the first non-digit
// character, which is left unread. Returns nonzero on failure. Fails
// if no digits are read before a non-digit is encountered.
int read_uint_ascii(FILE *f, uint32_t *out);
```

Now implement that function in `numlib.c`. Make sure to also write a
test program. Do *not* use `scanf()` or any other function in the
`scanf()` family.

### Hints

* The logic is very similar to the function developed in the Tuesday
  exercise.

* The loop has two stopping conditions: if the next character exists
  but is not a digit (e.g. a letter or whispace), or if there are no
  more characters to read (so that `fgetc()` returns EOF).

* When you find a non-digit character, use `ungetc()` to put it back.

* You can test with e.g. `echo 123 | ./your_test_program`.

* You can also create a test file and *redirect* the input to your
  program from that file, e.g., `./your_test_program <
  your_test_file`.

### Implementing `write_uint_ascii()`

Add the following prototype to `numlib.h`:

```C
// Write the provided integer in base-10 ASCII format to the given
// file. Returns 0 on success.
int write_uint_ascii(FILE *f, uint32_t x);
```
