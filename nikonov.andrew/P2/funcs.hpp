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
  double cos(const double& x, const size_t& numberMax, const double& absError);
  double stdcos(const double& x);
  void stringOutput(const double& x, const double& val, const double& stdval);
  void stringOutput(const double& x, const std::logic_error& e, const double& stdval);
}
#endif
