#ifndef TAYLOR_H
#define TAYLOR_H
#include <cstddef>
namespace kiselev
{
  double f(double x, size_t k, double error);
  double sqr_unox(double x);
  void output_table(double number, size_t k, double error);
  bool input_check1(double left, double right);
  bool input_check2(double right, size_t k);
}
#endif
