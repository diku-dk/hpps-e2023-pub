// fibs.c

#include <stdio.h>
#include <stdlib.h>
#include "fibs.h"

int* fibs(int n) {
  int* x = malloc(sizeof(int)*n);
  x[0] = 1;
  x[1] = 1;
  for (int i = 2; i < n; i++) {
    x[i] = x[i-1] + x[i-2];
  }
  return &x[0];
}
