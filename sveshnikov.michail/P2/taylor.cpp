#include "taylor.hpp"
#include <stdexcept>

double sveshnikov::taylor(double x, size_t k, double error)
{
  double next = x;
  int koef = 3;
  double result = next;
  for (size_t i = 1; i < k; ++i)
  {
    next = next * x * x / koef;
    result += next;
    koef += 2;
  }
  if (std::abs(next) > error)
  {
    throw std::logic_error("math-error");
  }
  return result;
}
