#ifndef NAMESPACES_H
#define NAMESPACES_H
#include <stdexcept>
#include <cmath>
#include <iostream>

namespace duhanina
{
  void output(double i, const size_t k, const double error);
  double f_taylor(double x, size_t k, double error);
  double stdf_taylor(double x);
}

#endif
