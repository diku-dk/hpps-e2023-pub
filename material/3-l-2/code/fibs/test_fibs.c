#include <stdio.h>
#include <stdlib.h>
#include "fibs.h"

int main() {
  int* x = fibs(10);
  for (int i = 0; i < 10; i++) {
    printf("fib(%d): %d\n", i, x[i]);
  }
  free(x);
}

