#ifndef FUNCS_H
#define FUNCS_H
#include <cstddef>
namespace alymova
{
  double taylor_row(const double x, const size_t k, const double error);
  double arctg(const double x);
  void print(const double x, const double taylor, const double math_func);
  void print_error(const double x, const double math_func);
}
#endif
