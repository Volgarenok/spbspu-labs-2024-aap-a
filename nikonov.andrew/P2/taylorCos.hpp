#ifndef TAYLORCOS_HPP
#define TAYLORCOS_HPP
#include <cstddef>
#include <cmath>
#include <stdexcept>
#include <cstring>
namespace nikonov
{
  double cos(const double& x, const size_t& numberMax, const double& absError);
  double stdcos(const double& x);
  void stringOutput(const double& x, const double& val, const double& stdval);
  void stringOutput(const double& x, const std::logic_error& e, const double& stdval);
}
#endif
