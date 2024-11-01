#include "taylorPolynomial.hpp"
#include <cmath>
#include <stdexcept>

double abramov::f(double x, size_t k, double error)
{
  double summand = 1;
  double sum = summand;
  size_t count = 2;
  for (; count <= k && count <= 10; ++count)
  {
    summand = summand * x / (count - 1);
    sum += summand;
    if (-1 * error <= summand && summand <= error)
    {
      break;
    }
  }
  if (!(-1 * error <= summand && summand <= error))
  {
    throw std::logic_error("<MATH_ERROR>");
  }
  else
  {
    return sum;
  }
}

double abramov::exp_x(double x)
{
  return std::exp(x);
}
