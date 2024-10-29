#ifndef TAYLOR_HPP
#define TAYLOR_HPP
#include <cstring>

namespace taylor
{
  const double error = 0.001;
  const double step = 0.05;
  double DoTaylor(double x, size_t k, double error);
  void PrintTableForTaylor(double left, double right, size_t k);
  void PrintStringTaylor(double current, size_t k);
}
#endif
