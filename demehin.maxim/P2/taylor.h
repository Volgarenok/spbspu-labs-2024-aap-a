#ifndef TAYLOR_H
#define TAYLOR_H
#include <cstddef>

namespace demehin
{
  double f(double x, size_t k, double error);
  double stdf(double x);
  void output(double x, size_t k, double error);
}
#endif

