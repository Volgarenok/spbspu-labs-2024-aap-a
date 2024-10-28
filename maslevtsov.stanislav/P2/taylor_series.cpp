#include <stdexcept>
#include <cmath>
#include "taylor_series.hpp"

double maslevtsov::taylorSeries(double x, size_t numberMax, const double absError)
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
