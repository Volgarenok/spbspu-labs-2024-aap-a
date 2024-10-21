#include "function.h"
#include <cmath>
double f(double x, size_t k, double error)
{
  if (error < 0)
  {
    throw std::invalid_argument("the margin of error should be positive");
  }
  if (k <= 0) {
    throw std::invalid_argument("counts should be positive");
  }
  double next = 1;
  double result = next;
  for (size_t i = 2; i < k; ++i)
  {
    if (i % 2 != 0)
    {
      next *= 0-(2 * (i - 1) - 1) * x / (2 * (i - 1));
    }
    else
    {
      next *= (2 * (i - 1) - 1) * x / (2 * (i - 1));
    }
    result += next;
  }
  if (std::abs(next) > error)
  {
    throw std::logic_error("math error");
  }
  return result;
}
