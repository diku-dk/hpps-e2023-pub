#include <stdio.h>
#include <assert.h>
#include "list.h"

int inc2(int x) {
  return x+2;
}

int main() {
  int x;
  struct list* l = list_empty();
  assert(list_is_empty(l));
  assert(list_remove_first(l, &x) == 1);
  assert(list_insert(10, l) == 0);
  assert(list_insert(20, l) == 0);
  assert(list_insert(30, l) == 0);
  assert(!list_is_empty(l));
  list_map(l, &inc2);
  assert(list_remove_first(l, &x) == 0);
  assert(x == 32);
  list_free(l);
}
