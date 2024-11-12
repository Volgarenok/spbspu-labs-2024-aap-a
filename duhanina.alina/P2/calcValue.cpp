#include "titletaylor.h"
#include <stdexcept>
#include <cmath>

double duhanina::calcValue(const double x, const size_t k, const double error)
{
  double next = 1;
  double result = next;
  for (size_t i = 1; i < k; ++i)
  {
    next *= (x * x) / (4 * i * i - 1);
    result += next;
  }
  if (std::abs(next) > error)
  {
    throw std::logic_error("math-error");
  }
  return result;
}

