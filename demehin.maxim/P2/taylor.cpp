#include <cmath>
#include "taylor.h"

double demehin::f(double x, size_t k, double)
{
  double next1 = 1;
  double next2 = x;
  double result = next1 + next2;
  for(size_t i = 2; i < k; ++i)
  {
    next2 = (next2 * x)/i;
    result += next2;
  }
  return result;
}

double demehin::stdf(double x)
{
  return exp(x);
}
