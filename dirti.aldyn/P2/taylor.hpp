#ifndef TAYLOR_HPP
#define TAYLOR_HPP
#include <cstddef>
#include <cmath>
#include <stdexcept>

namespace dirti
{
  void output(double x, size_t k, double error);
  double arcsin_math(double x);
  double arcsin_taylor(double x, size_t k, double error);
  double e_math(double x);
  double e_taylor(double x, size_t k, double error);
}


#endif
