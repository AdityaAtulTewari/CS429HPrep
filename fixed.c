#include <stdio.h>
int main()
{
  printf("10!:%d\n", factorial(10));
}

int factorial(int x)
{
  if(x == 0) return 1;
  return x * factorial(x-1);
}
