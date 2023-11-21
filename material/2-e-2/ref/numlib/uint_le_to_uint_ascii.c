#include "numlib.h"
#include <assert.h>

int main(int argc, char* argv[]) {
  assert(argc == 1);
  while (1) {
    uint32_t x;
    int r = read_uint_le(stdin, &x);
    if (r == 0) {
      if (write_uint_ascii(stdout, x) != 0) {
        fprintf(stderr, "%s: output error\n", argv[0]);
        return 1;
      }
      printf("\n");
    } else if (r == EOF) {
      return 0;
    } else {
      fprintf(stderr, "%s: input error\n", argv[0]);
      return 1;
    }
  }
}
