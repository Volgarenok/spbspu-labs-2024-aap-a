#include <cmath>
#include "namespace.h"

double aleksandrov::sinx_divx(double x)
{
  if (std::abs(x) < 1e-7)
  {
    return 1.0;
  }
  return sin(x)/x;
}

