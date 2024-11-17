#include "taylor.h"
#include <cmath>
double bocharov::sqrt1_x(double x)
{
  return std::sqrt(1 + x);
}
double bocharov::lnf(double x)
{
  return std::log(x + std::sqrt(x * x + 1));
}
