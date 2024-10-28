#ifndef MATHEMATICS_H
#define MATHEMATICS_H
#include <cmath>
#include <stdexcept>

namespace savintsev
{
  double calcFuncTaylor(double x, size_t k, double error);
  double calcFuncStd(double x);
}

#endif
