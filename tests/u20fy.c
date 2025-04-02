#include <stdio.h>

void u2ofy(int n, char a[]) {
  for (int i = 0; i < n; i++){
    if (a[i] == 'u') a[i] = 'o';
  }
  return;
}

int main() {
  char word[] = "muon";
  int length = 4;
  u2ofy(length, word);
  printf("%s\n", word);
  return 0;
}