#ifndef TITLETAYLOR_H
#define TITLETAYLOR_H
#include <cstddef>

namespace duhanina
{
  void output(double i, size_t k, double error);
  double calcValue(double x, size_t k, double error);
  double calcValueStd(double x);
}

#endif
