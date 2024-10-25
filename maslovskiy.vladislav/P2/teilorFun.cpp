#include "teilorFun.hpp"
#include <cmath>
#include <stdexcept>

double maslovskiy::teilorCos(const double& x, const size_t& k)
{
  const double error = 0.001;
  double next = 1;
  double res = next;
  double xPow = 1;
  double xFact = 2;
  double sign = 0;
  for (size_t i = 1; i < k; ++i)
  {
    if (i % 2 == 1)
    {
      sign = -1;
    }
    else
    {
      sign = 1;
    }
    xPow = xPow * x * x;
    next = sign * xPow / xFact;
    xFact = xFact * (xFact + 1) * (xFact + 2);
    res += next;
  }
  if (std::abs(res - std::cos(x)) > error)
  {
    throw std::logic_error("<MATH ERROR>");
  }
  return res;
}
