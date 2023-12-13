#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

#define MEMSIZE 10000

int main(void) {
  char* arr;
  // 2^34 is the limit for my laptop 
  int64_t memsize = (int64_t)pow(2, 34);
  arr = (char *)malloc(memsize);
  if (arr == NULL) {
    printf("Malloc failed, not enough virtual memory\n");
  }
  else {
    printf("Claimed %ld bytes of memory from %p to %p\n", memsize, arr, arr+memsize);
  }

  printf("Memory will not be freed until you hit a key\n");  
  getchar();  
  free(arr);
}
