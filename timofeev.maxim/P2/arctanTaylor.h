#ifndef ARCTAN_TAYLOR_H
#define ARCTAN_TAYLOR_H
#include <cstddef>
#include <cmath>
namespace timofeev
{
  double cal_arctan_taylor(double x, double abs_error, size_t number_max);
  void print_matrix(double start, double end, size_t number_max, double abs_error, double step);
}
#endif
