#ifndef MATHEMATICS_H
#define MATHEMATICS_H
#include <cstddef>

namespace savintsev
{
  double calcFuncTaylor(double x, size_t k, double error);
  double calcFuncStd(double x);
}

#endif
