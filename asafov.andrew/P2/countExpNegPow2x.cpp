#include <stdexcept>
#include "func.hpp"

double asafov::countExpNegPow2x(double x, size_t k, double error)
{
  double result = 0;
  for (size_t i = k; i > 0; i--)
  {
    result *= x * x / i;
    result += ((i % 2 == 0) ? (-1) : (1));
  }
  if (countAbsoluteError(x, k) > error)
  {
    throw std::logic_error("math-error");
  }
  return result;
}
