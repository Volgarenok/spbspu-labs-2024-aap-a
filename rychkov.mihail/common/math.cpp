#include "math.hpp"

#include <cmath>

bool rychkov::isAlmostEqual(double a, double b, int coef)
{
  double aBottom = a - (a - std::nextafter(a, std::numeric_limits< double >::min())) * coef;
  double aTop = a + (std::nextafter(a, std::numeric_limits< double >::max()) - a) * coef;
  return (b > aBottom) && (b < aTop);
}
