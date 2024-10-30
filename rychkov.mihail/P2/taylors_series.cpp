#include "taylors_series.hpp"

#include <stdexcept>
#include <cmath>

double rychkov::formulas::calcUnoDivSqr(double x, size_t maxDepth, double absError)
{
  double lastSummand = 1.0;
  double result = 1.0;
  for (size_t i = 0; i < maxDepth; i++)
  {
    lastSummand *= (i * 2) + 1;
    lastSummand /= (i * 2) + 2;
    lastSummand *= x * x;

    if (lastSummand < absError)
    {
      return result;
    }
    result += lastSummand;
  }
  throw std::runtime_error("required precision of Taylor's series was not reached");
}

double rychkov::formulas::calcUnoDivSqrWithStd(double x)
{
  return 1.0 / std::sqrt(1 - x * x);
}
