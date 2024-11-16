#include "brain.h"
#include <cmath>
double bocharov::sqrtln(double x, bool y)
{
  if (y == 0)
  {
    return std::sqrt(1 + x);
  }
  else
  {
    return std::log(x + std::sqrt(x * x + 1));
  }
}
