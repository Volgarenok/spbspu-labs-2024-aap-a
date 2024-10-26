#include "namespaces.h"

double duhanina::stdf_taylor(double x)
{
  double stdf_value = 1.0 / sqrt(1 - x * x);
  return stdf_value;
}
