#include "taylor.h"
#include <stdexcept>
#include <cmath>

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

double aleksandrov::sinxDivx(double x)
{
  if (std::abs(x) < 1e-7)
  {
    return 1.0;
  }
  return std::sin(x)/x;
}


