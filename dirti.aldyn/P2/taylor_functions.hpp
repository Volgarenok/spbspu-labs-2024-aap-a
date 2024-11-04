#ifndef TAYLOR_FUNCTIONS_HPP
#define TAYLOR_FUNCTIONS_HPP
#include <cstddef>

namespace dirti
{
  void output(double x, size_t k, double error);
  double math(double x);
  double taylor(double x, size_t k, double error);
}


#endif
