#ifndef TAYLOR_H
#define TAYLOR_H
#include <cstddef>

namespace aleksandrov
{
  double taylor(double x, size_t k, double error);
  double sinxDivx(double x);
}
#endif

