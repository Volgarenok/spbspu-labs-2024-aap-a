#ifndef TAYLOR_H
#define TAYLOR_H
#include <cstddef>
namespace demehin
{
  double f(double x, size_t k, double error);
  double stdf(double x);
  void output(double left, double right, const double step, const double error, const size_t k);
}
#endif
