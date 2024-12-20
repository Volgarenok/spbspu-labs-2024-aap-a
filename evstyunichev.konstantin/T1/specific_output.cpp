#include "specific_output.hpp"
#include <iostream>
#include <cmath>
#include "base-types.hpp"

double evstyunichev::roundToOneSign(double d)
{
  return round(d * 10) / 10;
}

void evstyunichev::frameOutput(rectangle_t a, std::ostream &out)
{
  out << roundToOneSign(a.pos.x  - a.width * 0.5) << ' '
    << roundToOneSign(a.pos.y - a.height * 0.5) << ' ' <<
    roundToOneSign(a.pos.x + a.width * 0.5) << ' ' <<
    roundToOneSign(a.pos.y + a.height * 0.5);
  return;
}
