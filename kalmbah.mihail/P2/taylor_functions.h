#ifndef TAYLOR_FUNCTIONS_H
#define TAYLOR_FUNCTIONS_H
#include <cstddef>

namespace kalmbah {
  unsigned long long getFactorial(size_t n);
  double getArcsinTaylor(double x, size_t n, double error);
  double getArctanTaylor(double x, size_t n, double error);
}

#endif
