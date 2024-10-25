#ifndef NAMESPACE_HPP
#define NAMESPACE_HPP
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <iomanip>
#include <cstring>
namespace karnauhova
{
  double f(double x, size_t k, double error);
  double stdf(double x);
  void output_row(double x, size_t k, double error, size_t width);
  void output_table(double left, double right, double step, size_t k, double error, size_t width);
}
#endif
