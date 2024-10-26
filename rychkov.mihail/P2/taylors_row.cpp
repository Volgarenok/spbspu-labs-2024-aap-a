#include "taylors_row.hpp"

#include <stdexcept>

double rychkov::calcUnoDivSqr(double x, size_t maxDepth, double requiredAbsError)
{
  double result = 1.0;
  size_t nominator = 1, denominator = 1;
  double xSqr = x*x, xMultiplier = 1.0;
  for (size_t i = 0; i < maxDepth; i++)
  {
    nominator *= (i * 2) + 1;
    denominator *= (i * 2) + 2;
    xMultiplier *= xSqr;

    double temp = nominator * xMultiplier / denominator;
    if (temp < requiredAbsError)
    {
      return result;
    }
    result += temp;
  }
  throw std::runtime_error("<MATH ERROR>");
}
