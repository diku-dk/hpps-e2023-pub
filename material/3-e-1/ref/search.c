#include <stdio.h>
#include <assert.h>

int main(int argc, char* argv[]) {
  assert(argc == 2);
  const char *fname = argv[1];

  FILE *f = fopen(fname, "r");
  assert(f != NULL);

  int c;
  int found = 0;
  while ((c = fgetc(f)) != EOF) {
    if (c == 'A') {
      found = 1;
      break;
    }
  }

  if (found) {
    printf("found\n");
  } else {
    printf("not found\n");
  }

  fclose(f);
}
