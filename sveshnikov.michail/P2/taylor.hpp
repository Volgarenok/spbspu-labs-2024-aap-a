#ifndef TAYLOR_HPP
#define TAYLOR_HPP
#include <iostream>
#include <cstddef>
#include <stdexcept>
namespace sveshnikov
{
  double taylor(double x, size_t k, double error);
  double math(double x);
  void row(double x, double value);
  double table();
}
#endif