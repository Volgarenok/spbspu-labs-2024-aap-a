#include "taylorSeries.hpp"
#include <cmath>
#include <stdexcept>

double smirnov::sinTaylor(double x, size_t k, double error)
{
  double next = x;
  double result = next;
  for (size_t i = 1; i < k; ++i)
  {
    next *= -x * x / ((2 * i) * (2 * i + 1));
    result += next;
  }
  if (std::abs(next) > error)
  {
    throw std::logic_error("math-error");
  }
  return result;
}

double smirnov::sinCmath(double x)
{
  return std::sin(x);
}
