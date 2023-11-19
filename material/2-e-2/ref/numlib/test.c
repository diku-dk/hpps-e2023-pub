// THis program tests both read_uint_ascii() and write_uint_ascii().

#include "numlib.h"
#include <stdio.h>

int main() {
  uint32_t x, y;
  read_uint_ascii(stdin, &x);
  skipspaces(stdin);
  read_uint_ascii(stdin, &y);

  write_uint_ascii(stdout, x+1);
  printf(" ");
  write_uint_ascii(stdout, y+1);
  printf("\n");
}
