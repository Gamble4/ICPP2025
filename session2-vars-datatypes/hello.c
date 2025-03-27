#include <stdio.h>

void addiIP(int* a, int num)
{
  *a += num;
}

union myunion
{
  int i;
  float f;
};


int main()
{
  int i =0;
  addiIP(&i, 6);
  printf("%d", i);
  printf( "%p %d", (void*) &i, i);
  return 0;
}

