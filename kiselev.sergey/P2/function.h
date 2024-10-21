#ifndef FUNCTION_H
#define FUNCTION_H
#include <cstddef>
#include <cstring>
namespace kiselev
{
  double f(double x, size_t k, double error);
  double sqr_unox(double x);
  void output_table(double number, size_t k, double error);
}
#endif
