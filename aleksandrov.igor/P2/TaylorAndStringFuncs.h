#ifndef TAYLORANDSTRINGFUNCS_H
#define TAYLORANDSTRINGFUNCS_H
#include <cstddef>

namespace aleksandrov
{
  double taylor(double x, size_t k, double error);
  double sinxDivx(double x);
  void printString(double i, size_t k, double error);
}
#endif
