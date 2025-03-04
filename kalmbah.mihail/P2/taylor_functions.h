#ifndef TAYLOR_FUNCTIONS_H
#define TAYLOR_FUNCTIONS_H
#include <cstddef>

namespace kalmbah
{
  unsigned long long factorial(size_t n);
  double arcsinTaylor(double x, size_t n, double error);
  double arctanTaylor(double x, size_t n, double error);
}

#endif
