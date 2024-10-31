#include "taylor_series.hpp"
#include <stdexcept>
#include <cmath>

double maslevtsov::taylorSeries(double x, size_t numberMax, double absError)
{
  double next = 1.0;
  double n = 1.0;
  double result = next;

  for (size_t i = 1; i < numberMax; ++i)
  {
    next *= x * x * ((n) / (n + 1.0));
    result += next;
    n += 2;
  }

  if (std::abs(next) > absError)
  {
    throw std::logic_error("math_error");
  }

  return result;
}
