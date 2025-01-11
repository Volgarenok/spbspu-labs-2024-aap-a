#include "math.hpp"

#include <cmath>
#include <limits>

bool rychkov::isAlmostEqual(double a, double b, double coef)
{
  double aBottom = a - getEpsilon(a, false) * coef;
  double aTop = a + getEpsilon(a, true) * coef;
  return (b > aBottom) && (b < aTop);
}
double rychkov::getEpsilon(double num, bool toPlusInfinity)
{
  if (toPlusInfinity)
  {
    return std::nextafter(num, std::numeric_limits< double >::max()) - num;
  }
  else
  {
    return num - std::nextafter(num, std::numeric_limits< double >::lowest());
  }
}
