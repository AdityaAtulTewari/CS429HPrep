include <stdio.h>
include <assert.h>
include <stdint.h>
//This is a simple algorithm
uint64_t mult(uint32_t a, uint32_t b);

int main()
{
  for(uint32_t i = 0; i < UINT8_MAX; i++)
  {
    for(uint32_t j = 0; j < UINT8_MAX; j++)
    assert(i*j == mult(i,j));
  }
}

uint64_t mult(uint32_t a, uint32_t b)
{
  if(a < b)
  {
    return mult(a,b);
  }
  if(b == 0) return 0;
  return b + mult(a, b-1);
}
