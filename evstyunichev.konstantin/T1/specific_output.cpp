#include "specific_output.hpp"
#include <iomanip>
#include <iostream>
#include "base-types.hpp"

void evstyunichev::frameOutput(rectangle_t a, std::ostream &out)
{
  size_t default_prec = out.precision();
  out << std::setprecision(1) << a.pos.x  - a.width * 0.5 << ' ' << a.pos.y - a.height * 0.5 << ' ' << a.pos.x + a.width * 0.5 << ' ' << a.pos.y + a.height * 0.5 << std::setprecision(default_prec);
  return;
}
