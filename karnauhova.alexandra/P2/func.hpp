#include <stdexcept>
#include <iostream>
#ifndef FUNC_HPP
#define FUNC_HPP
namespace karnauhova
{
  double f(double x, size_t k, double error);
  double stdf(double x);
  void output_row(double x, size_t k, double error, size_t width);
  void output_table(double left, double right, double step, size_t k, double error, size_t width);
}
#endif
