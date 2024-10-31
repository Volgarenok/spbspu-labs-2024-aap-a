#ifndef TAYLOR_COS_HPP
#define TAYLOR_COS_HPP
#include <cstddef>
namespace nikonov
{
  double cos(double x, size_t numberMax, double absError);
  double stdcos(double x);
}
#endif
