#include "checkup.h"

extern int x;

int check_value(int x) {
  if (x == 0) {
    return 0;
  } else if (x % 2 == 0) {
    return 1;
  } else {
    return 2;
  }
}