#ifndef TAYLOR_H
#define TAYLOR_H
#include <cstddef>
namespace bocharov
{
  double f(double x, size_t k, double error);
  double f2(double x, size_t k, double error);
  double sqrt1_x(double x);
  double lnf(double x);
  bool intervals(double left, double right);
  void table(double number, size_t k, double error);
  double sumf(double number, size_t k, double error);
  double sumf2(double number);
}
#endif
