#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "record.h"

int main(int argc, char** argv) {
  assert(argc == 2);

  int n;
  struct record* rs = read_records(argv[1], &n);

  for (int i = 0; i < n; i++) {
    printf("%s\n", rs[i].name);
  }

  free_records(rs, n);
}
