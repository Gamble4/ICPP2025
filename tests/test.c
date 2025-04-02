#include <stdio.h>
#include "checkup.h"

int x = 1;

int main() {
  const int vtype = check_value(x);
  switch (vtype) {
    case 1:
      printf("x is even\n");
      break;
    case 2:
      printf("x is odd\n");
    case 0:
      printf("x is zero\n");
  }
  return 0;
}