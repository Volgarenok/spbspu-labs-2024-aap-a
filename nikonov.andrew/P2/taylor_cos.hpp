#ifndef TAYLOR_COS_HPP
#define TAYLOR_COS_HPP
#include <cstddef>
#include <stdexcept>
namespace nikonov
{
  double cos(const double& x, const size_t& numberMax, const double& absError);
  double stdcos(const double& x);
}
#endif
