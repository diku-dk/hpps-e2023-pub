# Exercises

## Simple benchmarking

Implement the following simple programs in C and Python, and compare
their performance. If you find it too difficult to write your own
programs, use [our solutions](ref) - you can still do the performance
comparison youself.

### `search`/`search.py`

This program should take a filename as argument, open that file, and
say whether that file contains an ASCII `'A'` somewhere. Examples:

```
$ ./search contains_an_A
found
$ ./search contains_not_an_A
not found
```

You can create a 1GiB file with *random* with the following command:

```
$ dd if=/dev/urandom bs=1M count=1024 > random_bytes
```

Or a 1GiB file with *zero* bytes like this:

```
$ dd if=/dev/zero bs=1M count=1024 > zero_bytes
```

<details>
<summary>Open this to see possible observations</summary>

You will find that unless the input files are fairly large, the
runtime is very short for both programs. When benchmarking, always
make sure things run for a reasonable period of time (hundreds of
miliseconds as a rule of thumb).

If the input files contain an `'A'` early on, *and* they stop their
search early when an `'A'` is found, the runtime will be short,
despite the total size of the file. It is very likely that the file
with random bytes will contain an `'A'` early on.

With our programs, I observe that the Python program is actually
*faster* than the C program. To process a 1GiB file of zeroes, the C
program takes 4.569ss while the Python program takes 0.706s.

On the other hand, the Python program uses vastly more memory than the
C program, because it loads the entire file into memory in order to
perform a search. The C program reads a single character at a time.
This is a *time/space tradeoff*.
</details>

## Tombstone Diagrams

You have access to the following:

* an ARM machine,

* an interpreter for x86 written in ARM

* an interpreter for Python written in x86

* a compiler from F# to C written in Python

* a compiler from C to x86 written in ARM

* a compiler from MATLAB to ARM written in F#

Draw Tombstone diagrams for the following cases:

1. How to execute an x86 program.

2. How to execute an F# program.

3. How to execute a MATLAB program.
