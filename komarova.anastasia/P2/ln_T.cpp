#include "tableTeilor.h"
#include <cmath>

double komarova::lnTeilor(double x)
{
  return std::log(x + std::sqrt((x * x) + 1));
}

