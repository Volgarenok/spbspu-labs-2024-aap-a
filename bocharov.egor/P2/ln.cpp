#include "brain.h"
#include <cmath>
double bocharov::ln(double x)
{
  return std::log(x + std::sqrt(x * x + 1));
}
