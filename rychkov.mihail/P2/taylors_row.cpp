#include "taylors_row.hpp"

#include <stdexcept>
#include <cmath>

double rychkov::calcUnoDivSqr(double x, size_t maxDepth, double requiredAbsError)
{
  double xSqr = x * x;
  double temp = 1.0;
  double result = 1.0;
  for (size_t i = 0; i < maxDepth; i++)
  {
    temp *= (i * 2) + 1;
    temp /= (i * 2) + 2;
    temp *= xSqr;

    if (temp < requiredAbsError)
    {
      return result;
    }
    result += temp;
  }
  throw std::runtime_error("required precision of Taylor's row was not reached");
}

double rychkov::calcUnoDivSqrWithStd(double x)
{
  return 1.0 / std::sqrt(1 - x * x);
}
