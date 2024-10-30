#include "taylor.h"
#include <cmath>
#include <stdexcept>

double demehin::f(double x, size_t k, double error)
{
  double next1 = 1;
  double next2 = x;
  double result = next1 + next2;
  for (size_t i = 2; i < k; ++i)
  {
    next2 = (next2 * x) / i;
    result += next2;
  }
  if (std::abs(next2) > error)
  {
    throw std::logic_error("<MATH ERROR>");
  }
  return result;
}

double demehin::stdf(double x)
{
  return std::exp(x);
}
