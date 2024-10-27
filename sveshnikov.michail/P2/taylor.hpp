#ifndef TAYLOR_HPP
#define TAYLOR_HPP
#include <iostream>
#include <cstddef>
#include <stdexcept>
#include <cmath>
namespace sveshnikov
{
  double taylor(double x, size_t k, double error);
  double math(double x);
  void row(double x, size_t k, double error);
  void table(double left, double right, size_t k, const double error, const double step);
}
#endif