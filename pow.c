//This is a simple algorithm
uint64_t power(uint32_t a, uint32_t b);
uint64_t powe(uint32_t a, uint32_t b);

int main()
{
  for(uint32_t i = 1; i < 10; i++)
  {
    for(uint32_t j = 0; j < 10; j++)
    {
      assert(powe(i, j) == power(i, j));
    }
  }
}

uint64_t powe(uint32_t a, uint32_t b)
{
  if(b == 0) return 1;
  return a* powe(a, b-1);
}

uint64_t power(uint32_t a, uint32_t b)
{
  if(b == 0) return 1;
  if(b == 1) return a;
  if(b % 2 == 1)
  {
    return a* power(a, b-1);
  }
  else
  {
    return power(a*a, b >> 1);
  }
}
