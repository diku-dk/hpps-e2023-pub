#include <stdio.h>
#include <ctype.h>

int get_digit(void) {
  int c = getchar();
  if (isdigit(c)) {
    return c - 48;
  } else {
    return -1;
  }
}

int get_number(void) {
  int number = 0;
  while (1) {
    int d = get_digit();
    if (d != -1) {
      number = number * 10 + d;
    } else {
      return number;
    }
  }
}
