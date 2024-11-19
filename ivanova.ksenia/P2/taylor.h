#ifndef TAYLOR_H
#define TAYLOR_H
#include <cstddef>

namespace ivanova
{
  double arctg(double x, size_t k, double error);
  double exp(double x, size_t k, double error);
  double std_arctg(double x);
  double std_exp(double x);
  void output(double x, size_t k, double error);
}
#endif
