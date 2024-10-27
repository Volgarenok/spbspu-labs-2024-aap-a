#ifndef TAYLOR_TABLE_FUNCS_H
#define TAYLOR_TABLE_FUNCS_H
#include <cstddef>
namespace alymova
{
  double taylor_row(double x, size_t k, double error);
  double arctg(double x);
  void print(double x, double taylor, double math_func);
  void print_error(double x, double math_func);
}
#endif
