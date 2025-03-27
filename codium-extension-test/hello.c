#include <stdio.h>

void addiIP(int* a, int num)
{
  *a += num;
}

int main()
{
  int i =0;
  addiIP(&i, 6);
  printf("%d", i);
  printf("hello, world! \n");
  return 0;
}

