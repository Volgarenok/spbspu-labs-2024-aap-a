#include "spec_def.hpp"
#include <cmath>

bool evstyunichev::is_equal(double a, double b, double p)
{
  return (std::abs(a - b) <= p);
}

bool evstyunichev::is_int(double d)
{
  return (std::abs(d - std::round(d)) <= prec);
}
