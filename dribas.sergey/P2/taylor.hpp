#ifndef TAYLOR_HPP
#define TAYLOR_HPP
#include <cstddef>

namespace dribas
{
  double getTaylor(double x, size_t koll, double error);
  double getCmathValue(double x);
}
#endif
