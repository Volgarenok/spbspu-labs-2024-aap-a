#include <cstddef>
unsigned long long factorial(size_t n)
{
  unsigned long long result = 1;
  for (size_t i = 1; i <= n; ++i) {
    result *= i;
  }
  return result;
}
