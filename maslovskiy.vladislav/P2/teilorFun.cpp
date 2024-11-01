#include "teilorFun.hpp"
#include <cmath>
#include <stdexcept>

double maslovskiy::teilorCos(double x, size_t k, double error)
{
  double next = 1;
  double res = next;
  double xPow = 1;
  double xFact = 2;
  int sign = -1;
  for (size_t i = 1; i < k; ++i)
  {
    xPow = xPow * x * x;
    next = sign * xPow / xFact;
    xFact = xFact * (xFact + 1) * (xFact + 2);
    res += next;
    sign*= -1;
  }
  if (std::abs(res - std::cos(x)) > error)
  {
    throw std::logic_error("<MATH ERROR>");
  }
  return res;
}
