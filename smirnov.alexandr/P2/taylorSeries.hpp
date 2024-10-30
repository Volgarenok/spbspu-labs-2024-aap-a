#ifndef TAYLORSERIES_HPP
#define TAYLORSERIES_HPP
#include <ctddef>

namespace smirnov
{
  double sinTaylor(double x, size_t k, double error);
  double sinCmath(double x);
}
#endif
