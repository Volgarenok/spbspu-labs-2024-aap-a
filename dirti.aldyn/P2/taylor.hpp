#ifndef TAYLOR_FUNCTIONS_HPP
#define TAYLOR_FUNCTIONS_HPP
#include <cstddef>

namespace dirti
{
  void output(double x, size_t k, double error);
  double arcsin_math(double x);
  double arcsin_taylor(double x, size_t k, double error);
  double e_math(double x);
  double e_taylor(double x, size_t k, double error);
}


#endif
