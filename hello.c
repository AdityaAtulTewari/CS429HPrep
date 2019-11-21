<stdio.h>
int main()
{
  printf("10!:%d\n", factorial(5));
}

int factorial(int x)
{
  return x * factorial(x-1);
}
