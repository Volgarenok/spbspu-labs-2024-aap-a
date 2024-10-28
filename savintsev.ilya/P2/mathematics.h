#ifndef MATHEMATICS_H
#define MATHEMATICS_H
#include <cmath>
#include <stdexcept>

namespace savintsev
{
  double expNegPow2xTaylor(double x, size_t k, double error);
  double expNegPow2xStd(double x);
}

#endif
