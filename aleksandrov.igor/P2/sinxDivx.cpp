#include "TaylorAndStringFuncs.h"
#include <cmath>

double aleksandrov::sinxDivx(double x)
{
  if (std::abs(x) < 1e-7)
  {
    return 1.0;
  }
  return std::sin(x)/x;
}

