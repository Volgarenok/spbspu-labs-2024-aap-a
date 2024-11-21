#include "titletaylor.h"
#include <cmath>

double duhanina::calcValueStd(const double x)
{
  double stdf_value = 1.0 / std::sqrt(1 - x * x);
  return stdf_value;
}
