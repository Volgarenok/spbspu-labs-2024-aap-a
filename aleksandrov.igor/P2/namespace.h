#ifndef NAMESPACE_H
#define NAMESPACE_H
#include <cstddef>

namespace aleksandrov
{
  double taylor(double x, size_t k, double error);
  double sinx_divx(double x);
  void printString(double i, size_t k, double error);
}
#endif

