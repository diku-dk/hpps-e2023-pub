#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

#define MEMSIZE 10000

int main(void) {
  unsigned char* arr;
  // 2^34 is the limit for my laptop 
  int64_t memsize = (int64_t)pow(2, 34);
  int stride = 1000;
  int num_writes = 1000000;

  arr = malloc(memsize);
  if (arr == NULL) {
    printf("Malloc failed, not enough virtual memory\n");
  }
  else {
    printf("Claimed %ld bytes of memory from %p to %p\n", memsize, arr, arr+memsize);
  }

  while (1) {
    for (int i = 0; i < num_writes; i++) {
      arr[(i*stride) % memsize] = rand();
    }
  }
}
