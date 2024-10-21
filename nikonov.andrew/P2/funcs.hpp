#ifndef FUNCS_HPP
#define FUNCS_HPP
#include <cstddef>
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <cstring>
namespace nikonov
{
  double cos(double x, size_t numberMax, double absError);
  double stdcos(double x);
  void stringOupout(double x, double val1, double stdval);
  void stringOupout(double x, const std::logic_error& e, double stdval);
}
#endif
