#include "TaylorAndStringFuncs.h"
#include <stdexcept>

double aleksandrov::taylor(double x, size_t k, double error)
{
  double next = 1.0;
  double result = next;
  for (size_t i = 0; i < k; ++i)
  {
    next *= -1 * x * x / (2 * (i + 1) * (2 * (i + 1) + 1));
    result += next;
  }
  if (std::abs(next) > error)
  {
    throw std::logic_error("math-error");
  }
  return result;
}

