#include "numlib.h"
#include <stdint.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

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

int read_uint_ascii(FILE *f, uint32_t *out) {
  int read = 0;
  uint32_t num = 0;

  // The idea is simple: keep reading digits until there are no more.
  // The logic here is a bit complicated to properly handle EOF.
  while (1) {
    int c = fgetc(f);

    if (c >= '0' && c <= '9') {
      // We read a digit. The numerical value of the digit is its
      // ASCII code minus the numerical value of ASCII '0'.
      num = num * 10 + (c - '0');
    } else {
      // We might have read a non-digit character. Put it back
      // *unless* it is the special EOF marker (which is not a
      // digit!)
      if (c != EOF) {
        ungetc(c, f);
      }
      // If we encountered EOF on the *first* character read, then the
      // function fails with EOF. IF we encounter a non-digit as the
      // first character, then we fail with 1. Otherwise it succeeds.
      if (read == 0) {
        if (c == EOF) {
          return EOF;
        } else {
          return 1;
        }
      } else {
        *out = num;
        return 0;
      }
    }
    read++;
  }
}

int write_uint_ascii(FILE *f, uint32_t x) {
  if (fprintf(f, "%u", x) < 0) {
    return 1;
  } else {
    return 0;
  }
}

int write_uint_le(FILE *f, uint32_t x) {
  // Note that this is carefully written to produce little endian byte
  // ordering even if the host machine is big endian. I do this by
  // manually extracting each byte, using arithmetic instead of
  // address operations.
  fputc(x>>0,  f);
  fputc(x>>8,  f);
  fputc(x>>16, f);
  fputc(x>>24, f);
  return 0;
}

int read_uint_le(FILE *f, uint32_t *out) {
  int b0, b1, b2, b3;
  b0 = fgetc(f);

  if (b0 == EOF) {
    return EOF;
  }

  b1 = fgetc(f);
  b2 = fgetc(f);
  b3 = fgetc(f);

  if (b1 == EOF || b2 == EOF || b3 == EOF) {
    return 1;
  }

  *out =
    ((uint32_t)b0)
    | ((uint32_t)b1 << 8)
    | ((uint32_t)b2 << 16)
    | ((uint32_t)b3 << 24);
  return 0;
}
