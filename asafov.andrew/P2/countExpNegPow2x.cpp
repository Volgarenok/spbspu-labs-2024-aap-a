#include "countExpNegPow2x.h"
#include <stdexcept>

double asafov::countExpNegPow2x(double x, size_t k, double error)
{
  double ch = 1
  double result = 0;
  for (size_t i = 1; i <= k; i++)
  {
    result += ch;
    ch *= (-1) * x * x / i;
  }
  if (countAbsoluteError(x, k) > error)
  {
    throw std::logic_error("math-error");
  }
  return result;
}
